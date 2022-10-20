//7 numbers specify year, month, day, hour, minute, second, and millisecond (in that order)
//here month starts from 0(jan) and ends at 11(dec)


//Building a function to update the countdown in every milisecond

var x = setInterval(function(){
    var age25 = new Date("Aug 4, 2025 20:55");
    var age30 = new Date("Aug 4, 2030 20:55");
    var age40 = new Date("Aug 4, 2040 20:55");
    var age50 = new Date("Aug 4, 2050 20:55");
    var d = new Date();     //creating an object for the date i.e., todays' date
    // var c = new Date("Dec 21, 2021 ");       //rough date of new year
    var diff1 = age25-d;     //returns the number of miliseconds left
    var diff2 = age30-d;     //returns the number of miliseconds left
    var diff3 = age40-d;     //returns the number of miliseconds left
    var diff4 = age50-d;     //returns the number of miliseconds left
    
    var days1 = Math.floor(diff1/(24*60*60*1000));
    var hours1 = Math.floor(diff1%(24*60*60*1000)/(60*60*1000));
    var minutes1 = Math.floor(diff1%(60*60*1000)/(60*1000));
    var seconds1 = Math.floor(diff1%(60*1000)/(1000));

    var days2 = Math.floor(diff2/(24*60*60*1000));
    var hours2 = Math.floor(diff2%(24*60*60*1000)/(60*60*1000));
    var minutes2 = Math.floor(diff2%(60*60*1000)/(60*1000));
    var seconds2 = Math.floor(diff2%(60*1000)/(1000));

    var days3 = Math.floor(diff3/(24*60*60*1000));
    var hours3 = Math.floor(diff3%(24*60*60*1000)/(60*60*1000));
    var minutes3 = Math.floor(diff3%(60*60*1000)/(60*1000));
    var seconds3 = Math.floor(diff3%(60*1000)/(1000));

    var days4 = Math.floor(diff4/(24*60*60*1000));
    var hours4 = Math.floor(diff4%(24*60*60*1000)/(60*60*1000));
    var minutes4 = Math.floor(diff4%(60*60*1000)/(60*1000));
    var seconds4 = Math.floor(diff4%(60*1000)/(1000));

    // var milliseconds = Math.floor(diff%(1000))
    document.getElementById("demo1").innerHTML=days1+"d "+hours1+"h "+minutes1+"m "+seconds1+"s";
    document.getElementById("demo2").innerHTML=days2+"d "+hours2+"h "+minutes2+"m "+seconds2+"s";
    document.getElementById("demo3").innerHTML=days3+"d "+hours3+"h "+minutes3+"m "+seconds3+"s";
    document.getElementById("demo4").innerHTML=days4+"d "+hours4+"h "+minutes4+"m "+seconds4+"s";
},1);



// #####################################################################################################
// ################################## SNOW EFFECT ######################################################
// #####################################################################################################

var snow_fall_rate = 4 //decrease for faster fall speed
function snow() {  
  var b = document.createElement('div')
  var size = (Math.random()*10) + 5
  b.className = 'flake'
  b.style.width = size + 'px'
  b.style.height = size + 'px'
  b.style.position = 'fixed'
  b.style.zIndex = '9999'
  b.style.left = Math.random()*window.innerWidth + 'px'
  b.style.top = '-20px'
  b.style.borderRadius = '50%'
  b.style.background = 'white' 
  b.style.opacity = '.8' 
  b.style.filter = Math.random() < .5 ? 'blur(2px)' : 'blur(1px)'
  b.style.transition = Math.random < .5 ? snow_fall_rate*.75 + 's' : snow_fall_rate + 's'
  b.style.transitionTimingFunction = 'ease-in'
  document.body.appendChild(b)
 
  setTimeout(function(){
    var flakes = document.querySelectorAll('.flake')
    var flake = flakes[flakes.length - 1]  
    var flake_loc = flake.getBoundingClientRect()
    flake.style.top = '105%'
    flake.style.left = Math.random() < .5 ? flake_loc.left - 150 + 'px' : flake_loc.left + 150 + 'px'
  },10)  
 
  var flakes = document.getElementsByClassName('flake')
  for(var i=0;i<flakes.length;i++){
    if(flakes[i].getBoundingClientRect().top > window.innerHeight) {
      flakes[i].remove()
    }      
  }
  setTimeout(function(){ snow() },200)
}
snow()