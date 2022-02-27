function newgame(){
	document.getElementById("peniche").style.display='none';
	document.getElementById("gamemode").style.display='block';
    document.getElementById("loginer").style.display='none';
}

function setdific1(){
	document.getElementById("dificuldades").style.display='none';
    document.getElementById("cores").style.display='block';
    dificulty=1;
}
function setdific2(){
	document.getElementById("dificuldades").style.display='none';
    document.getElementById("cores").style.display='block';
    dificulty=3;
}
function setdific3(){
	document.getElementById("dificuldades").style.display='none';
    document.getElementById("cores").style.display='block';
    dificulty=5;
}

function gmodepc(){
    document.getElementById("gamemode").style.display='none';
    document.getElementById("dificuldades").style.display='block';
}

function gmodeplyr(){
    document.getElementById("gamemode").style.display='none';
    document.getElementById("jogo").style.display='block';
    document.getElementById("butmenu").style.display='block';
    document.getElementById("credits").style.display='block';
    document.getElementById("bturn").style.display='block';
    computerTurn=0;
    playerTurn=0;
   
}

function gmonline(){
    online = true;
    document.getElementById("gamemode").style.display='none';
    document.getElementById("gamemode2").style.display='none';
    document.getElementById("jogo").style.display='block';
    document.getElementById("credits").style.display='block';
    document.getElementById("oturn").style.display='block';
    document.getElementById("rankings").style.display='block';
    document.getElementById("logogame").style.display='block';


    join();
    ranking();
}

function login(){
	document.getElementById("peniche").style.display='none';
	document.getElementById("loginer").style.display='block';
}


function sgameb(){
    
    document.getElementById("cores").style.display='none';
    document.getElementById("jogo").style.display='block';
    document.getElementById("butmenu").style.display='block';
    document.getElementById("credits").style.display='block';
    document.getElementById("bturn").style.display='block';
    
        computerTurn=2;
        playerTurn=1;
    
}

function sgamew(){
    document.getElementById("cores").style.display='none';
    document.getElementById("jogo").style.display='block';
    document.getElementById("butmenu").style.display='block';
    document.getElementById("credits").style.display='block';
    document.getElementById("bturn").style.display='block';
        computerTurn=1;
        playerTurn=2;
        
        if(computerTurn==1 && firstPlay){
            autoPlay(computerTurn);
           firstPlay = false;
        }
}




function voltar1(){
    document.getElementById("loginer").style.display='none';
    document.getElementById("peniche").style.display='block';
}

function voltar2(){
    document.getElementById("dificuldades").style.display='none';
    document.getElementById("peniche").style.display='block';
}

function voltar3(){
    document.getElementById("cores").style.display='none';
    document.getElementById("peniche").style.display='block';
}

function showinstructions(){
    document.getElementById("instructions").style.display='block';
    document.getElementById("peniche").style.display='none';
    document.getElementById("jogarpeças").style.display='block';
}
function voltar4(){
    document.getElementById("instructions").style.display='none';
    document.getElementById("peniche").style.display='block';
}

function showscoreboard(){
    document.getElementById("scoreboard").style.display='block';
    document.getElementById("pcboard").style.display='block';
    document.getElementById("plyrboard").style.display='block';
    document.getElementById("scrbrdbut").style.display='none';

    whiteV = document.getElementById("pcboard");
    blackV = document.getElementById("plyrboard");

    whiteV.innerHTML = " Branco: " + localStorage.whiteVictories;
    blackV.innerHTML = " Preto: " + localStorage.blackVictories; 
    
}

function voltar5(){
    document.getElementById("scoreboard").style.display='none';   
    document.getElementById("scrbrdbut").style.display='block';
}

function desistir(){
   
    if (confirm("Tem a certeza que quer sair?")){    
    document.getElementById("jogo").style.display='none';
    document.getElementById("butmenu").style.display='none';
    document.getElementById("peniche").style.display='block';
    document.getElementById("scoreboard").style.display='none'; 
    document.getElementById("credits").style.display='none'; 
    document.getElementById("wturn").style.display='none';
    document.getElementById("bturn").style.display='none';
    document.getElementById("bwin").style.display='none';
    document.getElementById("wwin").style.display='none';
    document.getElementById("logogame").style.display='none';
    if(online==true){
     leave();
     document.getElementById("r").style.display='none';
     document.getElementById("oturn").style.display='none';
     
    }
    else{
        blackVictories=0;
        whiteVictories=0;
    }
    
    var preto =  document.getElementById("plyrboard");
    var branco =  document.getElementById("pcboard");

    preto.innerHTML = "Preto: " + localStorage.blackVictories;
    branco.innerHTML = "Branco: " + localStorage.whiteVictories;
    clearGame();  
    }

}

function playagain(){
    clearGame();
    document.getElementById("bwin").style.display='none';
    document.getElementById("wwin").style.display='none';
}

function next1(){
    document.getElementById("jogarpeças2").style.display='block';
    document.getElementById("jogarpeças").style.display='none';
}

function next2(){
    document.getElementById("passar").style.display='block';
    document.getElementById("jogarpeças2").style.display='none';
}

function instback1(){
    document.getElementById("jogarpeças").style.display='block';
    document.getElementById("jogarpeças2").style.display='none';
}

function instback2(){
    document.getElementById("jogarpeças2").style.display='block';
    document.getElementById("passar").style.display='none';
}

function gamescounter(){
    var preto =  document.getElementById("plyrboard");
    var branco =  document.getElementById("pcboard");

    preto.innerHTML = "Preto: " + blackVictories;
    branco.innerHTML = "Branco: " + whiteVictories;
}

function showrank(){
    document.getElementById("ranktitle").style.display='block';
    document.getElementById("ranking").style.display='block';
    document.getElementById("leaverank").style.display='block';
}

function leaverank(){
    document.getElementById("ranktitle").style.display='none';
    document.getElementById("ranking").style.display='none';
    document.getElementById("leaverank").style.display='none';
}