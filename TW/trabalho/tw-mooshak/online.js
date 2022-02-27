var url = "http://twserver.alunos.dcc.fc.up.pt:8008/";
var nickname;
var password;
var id="273974";
var jogo;
var turno;
var boardon;
var color;
var white;
var black;
var eventSource;
var adversario;


function ranking(){
    fetch(url+"ranking",{
        method: 'POST',
        body: JSON.stringify({})
    }).then(async response => {
        const rank=document.getElementById("ranking");
        const place = await response.json();
        
        for(var i=0;i<10;i++){
            
            var row = document.createElement("tr");
            
    
            for(var j=0;j<3;j++){
                var field = document.createElement("th");
                var text = document.createElement("h3");
                
    
                if(j==0){
                    
                    text.innerHTML = place.ranking[i].nick;
                    
                }
                
                if(j==1){
                    text.innerHTML = place.ranking[i].victories;
                }
    
                if(j==2){
                    text.innerHTML = place.ranking[i].games;
                }
                field.appendChild(text);
                row.appendChild(field);
            }
            rank.appendChild(row);
           
        }
       
        //return response.json();
    })
    
   /*.then(json =>{
        console.log(JSON.stringify (json));
    })*/
    
   

}

function register(){
    
    nickname= document.getElementById("username").value;
    password= document.getElementById("pass").value;
    console.log(nickname);
    console.log(password);
        

    
        fetch(url+"register",{
            method: 'POST',
            body: JSON.stringify({"nick": nickname, "pass": password})
        }).then(response => {
          
            if(response.ok){
                console.log(response);
                document.getElementById("peniche").style.display='none';
                document.getElementById("gamemode2").style.display='block';
                document.getElementById("loginer").style.display='none';
               

            }

            else{
                alert("User já registado com outra password");
            }
            
            return response;
        })

       /* .catch(error =>{
            alert("User já registado com outra password");
        }); */
        
        
}

function join(){
 
    fetch(url+"join",{
        method: 'POST',
        body: JSON.stringify({"group": id, "nick": nickname, "pass": password})
    }).then(response => {
            
            
            return response.json();
    
    })
    
    .then(json =>{
        jogo = json.game;
      if(json.color == "light") color = 2;
      else if(json.color == "dark" ) color = 1;
        console.log(jogo);
        console.log(color);

        eventSource = new EventSource(url+"update?nick="+nickname+"&game="+jogo);
        update();
    })




}

function leave(){
    fetch(url+"leave",{
        method: 'POST',
        body: JSON.stringify({"nick": nickname, "game": jogo, "pass": password})
    
    }).then(response => {
        console.log(response);

        count = null;
        boardon = [
            ["empty","empty","empty","empty","empty","empty","empty","empty"],
            ["empty","empty","empty","empty","empty","empty","empty","empty"],
            ["empty","empty","empty","empty","empty","empty","empty","empty"],
            ["empty","empty","empty","light","dark" ,"empty","empty","empty"],
            ["empty","empty","empty","dark", "light","empty","empty","empty"],
            ["empty","empty","empty","empty","empty","empty","empty","empty"],
            ["empty","empty","empty","empty","empty","empty","empty","empty"],
            ["empty","empty","empty","empty","empty","empty","empty","empty"]     
          ];
        turno = "TERMINADO";
        white = 2;
        black = 2;
        jogo = null;
        color = null;
        adversario = null;

        eventSource.close();
        return response.json();
      
    })

    
}


function notify(grow,gcol){

    console.log(grow,gcol);

    let move = null;
    
    if(grow != null || gcol != null){

    move = {
        "row" : grow,
        "column" : gcol
    }
}


    fetch(url+"notify",{
        method: 'POST',
        body: JSON.stringify({"nick": nickname, "pass": password, "game": jogo, "move": move })
    
    }).then(response => {
        console.log(response);    
    
    })
    


}

function update(flags){

    eventSource.onmessage = function(event) {
        
        const data = JSON.parse(event.data);

        console.log(JSON.stringify(data));

        boardon = data.board;
        turno = data.turn;
        white = data.count.light;
        black = data.count.dark;

        console.log(white);
        console.log(black);
        

        parseBoard(boardon);
        
        var dadiv = document.getElementById("sturn");
        dadiv.innerHTML = "TURNO " + turno;
        
        if(turno == nickname){
            
            if(color == 1){
                blackturn();
                console.log("changing turn");
           }
           else if(color == 2){
                whiteturn();
                console.log("changing turn");                
           }
        }

        else {
            adversario=turno;
            if(color == 1){
                whiteturn();
                console.log("changing turn");
           }
           else if(color == 2){
                blackturn();
                console.log("changing turn");
           }


        }

        displayMoves();
        drawPiece();
        scoreBoard.innerHTML = "Black: " + black + " White: " + white;

        console.log(JSON.stringify(board));

        if(data.skip == true){
            console.log("skipping");
            notify(null,null);
        }



        if(data.winner == "null"){
            if (confirm("Empate! \n Jogar Outra Vez?")){
                newogame();
            }
            else{
                desistir();
            }
        }
        
        else if(data.winner != undefined){
            if (confirm(data.winner + " Vencedor! \n Jogar Outra Vez?")){
                newogame();
            }
            else{
                desistir();
            }
        }
    }

}

function parseBoard(id){

    for(let row = 0 ; row < 8 ; row ++){
        for (let col = 0 ; col < 8 ; col++){
            if(id[row][col] === "empty") board[row][col] = 0;
            else if(id[row][col] === "dark") board[row][col] = 1;
            else if(id[row][col] === "light") board[row][col] = 2;
        }
    }
}


function newogame(){

    leave();
    join();
    
    displayMoves();
    drawPiece();
    scoreBoard.innerHTML = "Black: " + black + " White: " + white;
}