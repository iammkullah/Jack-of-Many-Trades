var buttonColours = ["red","blue","green","yellow"];
var userClickedPattern = [];
var randomChosenColour;
var gamePattern = [];
var level = 0;
var toogle = true;
var index=0;


function nextSequence() {
  var randomNumber = Math.random()*4;
  randomNumber = Math.floor(randomNumber);
  randomChosenColour = buttonColours[randomNumber];
  gamePattern.push(randomChosenColour);
  $("." + randomChosenColour).fadeOut(100).fadeIn(100);
  playSound(randomChosenColour);
}

function levelUp(){
    level++;
    $("h1").text("Level " + level);
    setTimeout(function(){
      nextSequence();
    }, 900);
}

function animatePress(currentColour){
  $("#" + currentColour).addClass("pressed");
  setTimeout(function(){
  $("#" + currentColour).removeClass("pressed");
  }, 100);
  $("#" + currentColour).fadeOut(100).fadeIn(100);
}

function wrongSound(){
  mySound = "sounds/wrong.mp3";
  var audio = new Audio(mySound);
  audio.play();
}

function startOver(){
  toogle = true;
  index = 0;
  level = 0;
  userClickedPattern.length = 0;
  gamePattern.length = 0;
}

function playSound(name){
  mySound = "sounds/" + name + ".mp3";
  var audio = new Audio(mySound);
  audio.play();
}

function checkAnswer(){
    if(userClickedPattern[index] != gamePattern[index]){
      $("h1").text("Game Over, Press Any Key to Restart");
      $("body").addClass("game-over");
      setTimeout(function(){
      $("body").removeClass("game-over");
      }, 100);
      wrongSound();
      startOver();
    }
    else{
      index++;
      if(index == level){
        levelUp();
        index = 0;
        userClickedPattern.length = 0;
      }
    }
}

$(document).keypress(function(){
  if(toogle == true){
    levelUp();
    toogle = false;
  }
});

$(".btn").click(function(event){
  var userChosenColour = $(event.target).attr('id');
  userClickedPattern.push(userChosenColour);
  animatePress(userChosenColour);
  playSound(userChosenColour);
  checkAnswer();
});
