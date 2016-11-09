var socket = io();

var MOVEMENTS = ['FORWARD', 'STOP', 'Left', 'Right', 'K1', 'K2', 'K3', 'K4', 'K5', 'K6', 'K7', 'K8', 'K9', 'Q1', 'Q2', 'Q3', 'Q4', 'Q5', 'Q6', 'Q7', 'Q8', 'Q9','FF'];

var flagf = true;
var flagb = true;
var flagr = true;
var flagl = true;
var flags = true;
var dir = 'a';

// send set speeds
function updateTextInput(val, sliderTextID) {
  document.getElementById(sliderTextID).value=val;
  console.log(sliderTextID);
  pwmm = val;
  socket.emit('Amplitude', {pwmm});
}

// send out Left message over socket
function K1() {
	dir = 'k';
    	socket.emit('K1',{dir});
}// send out Left message over socket
function FF() {
	dir = 'j';
    	socket.emit('FF',{dir});
}// send out Left message over socket
function K2() {
	dir = 'l';
    	socket.emit('K2',{dir});
}// send out Left message over socket
function K3() {
	dir = 'm';
    	socket.emit('K3',{dir});
}// send out Left message over socket
function K4() {
	dir = 'n';
    	socket.emit('K4',{dir});
}// send out Left message over socket
function K5() {
	dir = 'o';
    	socket.emit('K5',{dir});
}// send out Left message over socket
function K6() {
	dir = 'p';
    	socket.emit('K6',{dir});
}// send out Left message over socket
function K7() {
	dir = 'q';
    	socket.emit('K7',{dir});
}// send out Left message over socket
function K8() {
	dir = 'r';
    	socket.emit('K8',{dir});
}// send out Left message over socket
function K9() {
	dir = 's';
    	socket.emit('K9',{dir});
}
function Q1() {
	dir = 'i';
    	socket.emit('Q1',{dir});
}
function Q2() {
	dir = 'h';
    	socket.emit('Q2',{dir});
}
function Q3() {
	dir = 'g';
    	socket.emit('Q3',{dir});
}
function Q4() {
	dir = 'f';
    	socket.emit('Q4',{dir});
}
function Q5() {
	dir = 'e';
    	socket.emit('Q5',{dir});
}
function Q6() {
	dir = 'd';
    	socket.emit('Q6',{dir});
}
function Q7() {
	dir = 'c';
    	socket.emit('Q7',{dir});
}
function Q8() {
	dir = 'b';
    	socket.emit('Q8',{dir});
}
function Q9() {
	dir = 'a';
    	socket.emit('Q9',{dir});
}
// send out Stop message over socket
function FORWARD() {
	dir = 'j';
    	socket.emit('FORWARD',{dir});
}

