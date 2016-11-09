var socket = io();

var MOVEMENTS = ['Forward'];

var flagf = true;
var flagb = true;
var flagr = true;
var flagl = true;
var flags = true;
var pwmm = 0;
var ori = 0;
var diro = 0;
var dir = 0;

// send set speeds
function updateTextInput(val, sliderTextID) {
  document.getElementById(sliderTextID).value=val;
  console.log(sliderTextID);
  pwmm = val;
  socket.emit('Amplitude', {pwmm});
}

function FORWARD() {
    	socket.emit('FORWARD');
}

