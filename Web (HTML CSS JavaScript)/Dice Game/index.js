var randomNumber1 = (Math.random()*6)+1;
randomNumber1 = Math.floor(randomNumber1);
console.log(randomNumber1);
randomDiceImage1 = "images/dice" + randomNumber1 + ".png";
document.querySelectorAll("img")[0].setAttribute("src",randomDiceImage1);

var randomNumber2 = (Math.random()*6)+1;
randomNumber2 = Math.floor(randomNumber2);
console.log(randomNumber1);
randomDiceImage2 = "images/dice" + randomNumber2 + ".png";
document.querySelectorAll("img")[1].setAttribute("src",randomDiceImage2);

if(randomNumber1 > randomNumber2) {
  document.querySelector("h1").innerText = "Player 1 Wins";
}
else if(randomNumber1 < randomNumber2) {
  document.querySelector("h1").innerText = "Player 2 Wins";
}

else {
  document.querySelector("h1").innerText = "Draw!";
}
