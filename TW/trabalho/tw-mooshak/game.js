/*variaveis de display */

var boardBackground;
var showMoves;
var gap = 3;
var cellWidth = 65;
var pLayer;
var online;


/*variaveis do jogo*/

var turn = 1;
var scoreBoard;
var gameOver = false;
var playerTurn=0;
var computerTurn=0;
var firstPlay = true;
var maxScore;
var dificulty;
localStorage.whiteVictories;
localStorage.blackVictories;
var whitev = 0;
var blackv = 0;

var board = [
    [0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0],
    [0,0,0,2,1,0,0,0],
    [0,0,0,1,2,0,0,0],
    [0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0]
];

/* funcões de display do jogo*/

window.onload=function(){
    scoreBoard = document.getElementById("score");
    showMoves = document.getElementById("displayMoves");
    boardBackground = document.getElementById("boardBackground");
    pLayer = document.getElementById("pLayer");
    boardBackground.style.width = cellWidth*8 +(gap*9);
    boardBackground.style.height = cellWidth*8 + (gap*9);

    drawSingleCells();
    drawPiece();
    displayMoves();
    if(computerTurn==1 && firstPlay){
        autoPlay(computerTurn,dificulty);
       firstPlay = false;
    }
    
};

function drawSingleCells(){
    for(var row = 0; row < 8;row++)
    {
        for(var col = 0; col < 8;col++)
        {
            var singleCell = document.createElement("div");
            singleCell.style.position = "absolute";
            singleCell.style.width = cellWidth;
            singleCell.style.height = cellWidth;
            singleCell.style.backgroundColor="gray";
            singleCell.style.left = (cellWidth+gap)*col+gap;
            singleCell.style.top = (cellWidth+gap)*row+gap;
            singleCell.setAttribute("onclick","makeMove("+row+","+col+")");
            
            
          
                 
            boardBackground.appendChild(singleCell);
}
}
}



function drawPiece(){

    pLayer.innerHTML = "";

    for(var row = 0; row < 8;row++)
    {
        for(var col = 0; col < 8;col++)
        {
            var value = board[row][col];
            if( value === 0) continue;

            else {
                var piece = document.createElement("div");
                    piece.style.position = "absolute";
                    piece.style.width = cellWidth-4;
                    piece.style.height = cellWidth-4;
                    piece.style.borderRadius = "50%";
                    piece.style.left = (cellWidth+gap)*col+gap+2;
                    piece.style.top = (cellWidth+gap)*row+gap+2;

                if(value == 1) piece.style.backgroundColor = "black";
                if(value == 2) piece.style.backgroundColor="white";
                
                pLayer.appendChild(piece);

            }

        }
     }
}


function displayMoves(){

    showMoves.innerHTML = "";

        for(var row = 0; row < 8; row++){
            for(var col = 0; col < 8; col++){

                    if(canClickSpot(board,turn,row,col)){

                        var shadowPiece = document.createElement("div");
                        shadowPiece.style.position = "absolute";
                        shadowPiece.style.width = cellWidth-4;
                        shadowPiece.style.height = cellWidth-4;
                        shadowPiece.style.borderRadius = "50%";
                        shadowPiece.style.left = (cellWidth+gap)*col+gap+2;
                        shadowPiece.style.top = (cellWidth+gap)*row+gap+2;
                        shadowPiece.style.opacity = 0.5;
                        shadowPiece.style.zIndex = 2;
                        shadowPiece.setAttribute("onclick","makeMove("+row+","+col+")");
                        

                        if(turn == 1) shadowPiece.style.background = "black";
   
                      if(turn == 2) shadowPiece.style.background="white";
    
                    showMoves.appendChild(shadowPiece);

                             }
                          }
                        }
                    }


function drawScore(){
 
    var whiteScore = 0;
    var blackScore = 0;
         
    for(var row = 0; row < 8; row++){
        for(var col = 0; col < 8; col++){
                            
                var value = board[row][col];
                    
                if(value == 1) blackScore+=1;
                else if(value == 2) whiteScore+=1;
                
            }
            
        }
                    
        if(blackScore > whiteScore) maxScore = 1;
        else if(whiteScore > blackScore) maxScore = 2;
        else if( whiteScore == blackScore) maxScore = 0;                
                        
        scoreBoard.innerHTML = "Black: " + blackScore + " White: " + whiteScore;
                    
    }
                    

 function clearGame(){

    board = [
        [0,0,0,0,0,0,0,0],
        [0,0,0,0,0,0,0,0],
        [0,0,0,0,0,0,0,0],
        [0,0,0,2,1,0,0,0],
        [0,0,0,1,2,0,0,0],
        [0,0,0,0,0,0,0,0],
        [0,0,0,0,0,0,0,0],
        [0,0,0,0,0,0,0,0]
    ];

    turn = 1;
    firstPlay = true;
    gameOver = false;

    drawPiece();
    displayMoves();
    drawScore();

 }


 /* funções do jogo */


function makeMove(row,col){
       
        if(online === true){
            notify(row,col);
            update();
       return;
       
    }

 
    else{
        if(computerTurn !== 0){

        if(turn == playerTurn){  
         placePiece(row,col);
         autoPlay(computerTurn,dificulty);
         return;
    }
}

        else if(computerTurn === 0){
         placePiece(row,col);
          return;
}

  
    }
}

function placePiece(row,col){
    if(canClickSpot(board,turn,row,col) === true){
     
        
        board[row][col] = turn;
        var affectedPiece = checkPositions(board,turn,row,col);
        flipPiece(board,affectedPiece);

        if(turn == 1 && canPlay(board,2)){
             turn = 2;
             document.getElementById("wturn").style.display='block';
             document.getElementById("bturn").style.display='none'; 
        }
        else if(turn == 2 && canPlay(board,1)){
             turn = 1;
             document.getElementById("bturn").style.display='block';
             document.getElementById("wturn").style.display='none'; 
        }
        
        drawPiece();
        displayMoves();
        drawScore();

        verifyGameOver();
    }

    return;
}

function checkPositions(pieces,id,row,col){
    var affectedPiece= [];


    //direita
    var couldBeAffected = [];
    var colIterator = col;

    while(colIterator < 7){
        colIterator +=1;
        var valueAtSpot = pieces[row][colIterator];
        if(valueAtSpot === 0 || valueAtSpot == id){
            if(valueAtSpot == id){
                affectedPiece = affectedPiece.concat(couldBeAffected);
            }
            break;
        }
        else{

            var pieceLocation = {row:row,col:colIterator};
            couldBeAffected.push(pieceLocation);

        }
    }


       //Esquerda

    couldBeAffected = [];
    colIterator = col;

    while(colIterator > 0){
        colIterator -=1;
        var valueAtSpot = pieces[row][colIterator];
        if(valueAtSpot === 0 || valueAtSpot == id){
            if(valueAtSpot == id){
                affectedPiece = affectedPiece.concat(couldBeAffected);
            }
            break;
        }
        else{

             var pieceLocation = {row:row,col:colIterator};
            couldBeAffected.push(pieceLocation);

        }
    }

  // cima

    couldBeAffected = [];
    var rowIterator = row;

    while(rowIterator > 0 ){
        rowIterator -=1;
        var valueAtSpot = pieces[rowIterator][col];
        if(valueAtSpot === 0 || valueAtSpot == id){
            if(valueAtSpot == id){
                affectedPiece = affectedPiece.concat(couldBeAffected);
            }
            break;
        }
        else{

            var pieceLocation = {row:rowIterator,col:col};
            couldBeAffected.push(pieceLocation);

        }
    }

        //baixo

    couldBeAffected = [];
    rowIterator = row;

    while(rowIterator < 7){
        rowIterator +=1;
        var valueAtSpot = pieces[rowIterator][col];
        if(valueAtSpot === 0 || valueAtSpot == id){
            if(valueAtSpot == id){
                affectedPiece = affectedPiece.concat(couldBeAffected);
            }
            break;
        }
        else{

            var pieceLocation = {row:rowIterator,col:col};
            couldBeAffected.push(pieceLocation);

        }
    }

    // baixo direita

    couldBeAffected = [];
    rowIterator = row;
    colIterator = col;
    while(rowIterator < 7 && colIterator < 7){
        rowIterator +=1;
        colIterator +=1;
        var valueAtSpot = pieces[rowIterator][colIterator];
        if(valueAtSpot === 0 || valueAtSpot == id){
            if(valueAtSpot == id){
                affectedPiece = affectedPiece.concat(couldBeAffected);
            }
            break;
        }
        else{

            var pieceLocation = {row:rowIterator,col:colIterator};
            couldBeAffected.push(pieceLocation);

        }
    }

    // baixo esquerda

    couldBeAffected = [];
    rowIterator = row;
    colIterator = col;

    while(rowIterator < 7 && colIterator > 0){
        rowIterator +=1;
        colIterator -=1;
        var valueAtSpot = pieces[rowIterator][colIterator];
        if(valueAtSpot === 0 || valueAtSpot == id){
            if(valueAtSpot == id){
                affectedPiece = affectedPiece.concat(couldBeAffected);
            }
            break;
        }
        else{

            var pieceLocation = {row:rowIterator,col:colIterator};
            couldBeAffected.push(pieceLocation);

        }
    }

    // cima direita

    couldBeAffected = [];
    rowIterator = row;
    colIterator = col;

    while(rowIterator > 0 && colIterator < 7){
        rowIterator -=1;
        colIterator +=1;
        var valueAtSpot = pieces[rowIterator][colIterator];
        if(valueAtSpot === 0 || valueAtSpot == id){
            if(valueAtSpot == id){
                affectedPiece = affectedPiece.concat(couldBeAffected);
            }
            break;
        }
        else{

            var pieceLocation = {row:rowIterator,col:colIterator};
            couldBeAffected.push(pieceLocation);

        }
    }

    //cima esquerda 

    couldBeAffected = [];
    rowIterator = row;
    colIterator = col;

    while(rowIterator > 0 && colIterator < 7){
        rowIterator -=1;
        colIterator -=1;
        var valueAtSpot = pieces[rowIterator][colIterator];
        if(valueAtSpot === 0 || valueAtSpot == id){
            if(valueAtSpot == id){
                affectedPiece = affectedPiece.concat(couldBeAffected);
            }
            break;
        }

        else{

            var pieceLocation = {row:rowIterator,col:colIterator};
            couldBeAffected.push(pieceLocation);

        }
    }

    return affectedPiece;
}

function canClickSpot(pieces,id,row,col){

        var affectedPiece = checkPositions(pieces,id,row,col);
        if (pieces[row][col] !== 0 || affectedPiece.length === 0) return false;
    
        else return true;
    }
    
function canPlay(pieces,id){

        for(var row = 0; row < 8; row++){
            for( var col = 0; col < 8; col++){
              if(canClickSpot(pieces,id,row,col)) return true;
            }
        }
    
        return false;
    }


function flipPiece(pieces,affectedPiece){

        for(var i = 0; i<affectedPiece.length;i++){

            var pos = affectedPiece[i];
            if(pieces[pos.row][pos.col] == 1) pieces[pos.row][pos.col] = 2;
   
            else pieces[pos.row][pos.col] = 1;
        }
   }

function verifyGameOver(){
    
    if(canPlay(board,1) === false && canPlay(board,2) === false){
        endGame();
    }

    else if (canPlay(board,1) && canPlay(board,2) === false){
         turn = 1;
         document.getElementById("bturn").style.display='block';
         document.getElementById("wturn").style.display='none'; 
    }
    else if (canPlay(board,2) && canPlay(board,1) === false){
         turn = 2;
         document.getElementById("wturn").style.display='block';
         document.getElementById("bturn").style.display='none'; 
    }

    return;
}

function endGame(){
    switch(maxScore){
    case 1: 
        blackv +=1;
        document.getElementById("bwin").style.display='block';
        localStorage.setItem("blackVictories",blackv);

        break;
    case 2: 
        document.getElementById("wwin").style.display='block';
        whitev +=1;
        localStorage.setItem("whiteVictories",whitev);
        break;
    case 0:
        alert("Tie!");
        break;
    }
    
   

}


/* AI */

function autoPlay(Cturn,depth){

    var positions = generateChild(board,Cturn);      //gera as jogadas possiveis para o computador naquele turno.
      
    if(positions.length === 0){                        // se não existirem jogadas possiveis termina o turno;    
        turn=playerTurn; 
        return;              
    }

    else{
        var currentState;
        var maxPlay = -999;
        var bestMove = [];

        for(var i = 0; i < positions.length; i++){
             currentState = [];
             var move = positions[i];
             var score;
            copyBoard(board,currentState);
            currentState[move[0]][move[1]] = Cturn;
            var affected = checkPositions(currentState,Cturn,move[0],move[1]);
            flipPiece(currentState,affected);

            score = minimax(currentState,depth,Cturn,Cturn,-999,999);       

            if(score > maxPlay){
                maxPlay = score;
                bestMove[0] = move[0];
                bestMove[1] = move[1];
            }
        }
        placePiece(bestMove[0],bestMove[1]);

        return;

        }
}

function minimax(position,depth,Cturn,thisTurn,alpha,beta){                   //tabuleiro,profundidade, turno do computador(max) e turno atual


    if(depth === 0 || (canPlay(position,1) === false && canPlay(position,2) === false)){
     return mmScore(position,Cturn);
    }

    var otherTurn = 2;
    if(thisTurn == 2) otherTurn = 1;


    var positions = generateChild(position,thisTurn);

    if(positions.length === 0) return minimax(position,depth-1,Cturn,otherTurn); //passar jogada
    
    else{
        var bestScore;
        bestScore = -999;
        if(Cturn != thisTurn) bestScore = 999;

        for(var i = 0; i < positions.length; i++){
           
            var simBoard = [];
            var move = positions[i];

            copyBoard(position,simBoard);
            simBoard[move[0]][move[1]] = thisTurn;
            var affected = checkPositions(simBoard,thisTurn,move[0],move[1]);
            flipPiece(simBoard,affected);

            var score = minimax(simBoard,depth-1,Cturn,otherTurn,alpha,beta);

            if(Cturn == thisTurn){
                bestScore = Math.max(bestScore,score);
                alpha = Math.max(score,alpha);     
            }

            else{
                bestScore = Math.min(bestScore,score);
                beta = Math.min(beta,score);      
            }

            if(beta<=alpha){
                 break;
            }  
           

        }

        return bestScore;
     }
 
    }

    function generateChild(position,id){
        var allpos=[];

        for(var row = 0; row < 8; row++){
            for(var col = 0; col < 8; col++){
    
                if(canClickSpot(position,id,row,col)){
                    var pos = [row,col];                
                    allpos.push(pos);
                }
            }
        }

        return allpos;
}

function mmScore(position,someTurn){

    var thisScore = 0;
    var otherScore = 0;

    var otherTurn = 1;
    if(someTurn == 1) otherTurn = 2;

    for(var row = 0; row < 8; row++){
            for(var col = 0; col < 8;col++){
    
                if(position[row][col] == someTurn) thisScore++;
                if(position[row][col] == otherTurn) otherScore++; 
            }
        }
    
        return (thisScore - otherScore);
    }


function copyBoard(originalBoard,copyBoard){

    for(var i = 0 ; i < originalBoard.length; i++){
        copyBoard[i] = originalBoard[i].slice();
       }
   
}


function whiteturn(){
    turn = 2; 
    return;
}

function blackturn(){
    turn = 1; 
    return;
}