var express = require('express'); 			// web server application
var http = require('http');				// http basics
var app = express();					// instantiate express server
var server = http.Server(app);				// connects http library to server
var io = require('socket.io')(server);			// connect websocket library to server
var serialport = require('serialport');			// serial library
var serverPort = 8000;
var pwmmm;
var orient='j';
var tame=1212;
var lame=1212;
var fs = require('fs');
var ardmsg;
var stream = fs.createWriteStream('nodejs_arduino.txt', {flags: 'w'});

// use express to create the simple webapp
app.use(express.static('public'));		// find pages in public directory

// check to make sure that the user calls the serial port for the arduino when
// running the server
	if(!process.argv[2]) {
    	console.error('Usage: node '+process.argv[1]+' SERIAL_PORT');
    	process.exit(1);
    }

 //start the serial port connection and read on newlines
var serial = new serialport.SerialPort(process.argv[2], {
    parser: serialport.parsers.readline('\r\n')
    });	

// this is the websocket event handler and say if someone connects
// as long as someone is connected, listen for messages
io.on('connect', function(socket) {
	
	///////////////////////////////
tame = (Date.now()/1000);
lame = tame.toString();
	stream.write("TIME START: ");
	stream.write(lame);
	stream.write("\n");
console.log('TIME HERE:');
console.log(lame);
	//////////////////////////////

        console.log('a user connected');
    	socket.on('error', function (err) { 
	console.error(err.stack); // TODO, cleanup 
	});
    // if you get the 'Left' msg, send an 'l' to the arduino
    	socket.on('K1', function(data) {
	orient = data.dir;
        console.log('k1');
        serial.write(orient);

	///////////////////////////////
tame = (Date.now()/1000);
lame = tame.toString();
console.log('TIME HERE:');
console.log(lame);
	///////////////////////////////	
	
    });
    // if you get the 'Left' msg, send an 'l' to the arduino
    	socket.on('K2', function(data) {
	orient = data.dir;
        console.log('k2');
        serial.write(orient);
	

	///////////////////////////////
tame = (Date.now()/1000);
lame = tame.toString();
console.log('TIME HERE:');
console.log(lame);
	///////////////////////////////	
    });
    // if you get the 'Left' msg, send an 'l' to the arduino
    	socket.on('K3', function(data) {
	orient = data.dir;
        console.log('k3');
        serial.write(orient);

	///////////////////////////////
tame = (Date.now()/1000);
lame = tame.toString();
console.log('TIME HERE:');
console.log(lame);
	///////////////////////////////	
	
    });
    // if you get the 'Left' msg, send an 'l' to the arduino
    	socket.on('K4', function(data) {
	orient = data.dir;
        console.log('k4');
        serial.write(orient);

	///////////////////////////////
tame = (Date.now()/1000);
lame = tame.toString();
console.log('TIME HERE:');
console.log(lame);
	///////////////////////////////	
	
    });
    // if you get the 'Left' msg, send an 'l' to the arduino
    	socket.on('K5', function(data) {
	orient = data.dir;
        console.log('k5');
        serial.write(orient);

	///////////////////////////////
tame = (Date.now()/1000);
lame = tame.toString();
console.log('TIME HERE:');
console.log(lame);
	///////////////////////////////	
	
    });
    // if you get the 'Left' msg, send an 'l' to the arduino
    	socket.on('K6', function(data) {
	orient = data.dir;
        console.log('k6');
        serial.write(orient);

	///////////////////////////////
tame = (Date.now()/1000);
lame = tame.toString();
console.log('TIME HERE:');
console.log(lame);
	///////////////////////////////	
	
    });
    // if you get the 'Left' msg, send an 'l' to the arduino
    	socket.on('K7', function(data) {
	orient = data.dir;
        console.log('k7');
        serial.write(orient);

	///////////////////////////////
tame = (Date.now()/1000);
lame = tame.toString();
console.log('TIME HERE:');
console.log(lame);
	///////////////////////////////	
	
    });
    // if you get the 'Left' msg, send an 'l' to the arduino
    	socket.on('K8', function(data) {
	orient = data.dir;
        console.log('k8');
        serial.write(orient);
	///////////////////////////////
tame = (Date.now()/1000);
lame = tame.toString();
console.log('TIME HERE:');
console.log(lame);
	///////////////////////////////	
	
    });
    // if you get the 'Left' msg, send an 'l' to the arduino
    	socket.on('K9', function(data) {
	orient = data.dir;
        console.log('k9');
        serial.write(orient);
	///////////////////////////////
tame = (Date.now()/1000);
lame = tame.toString();
console.log('TIME HERE:');
console.log(lame);
	///////////////////////////////	
	
    });
    // if you get the 'Left' msg, send an 'l' to the arduino
    	socket.on('Q1', function(data) {
	orient = data.dir;
        console.log('q1');
        serial.write(orient);

	///////////////////////////////
tame = (Date.now()/1000);
lame = tame.toString();
console.log('TIME HERE:');
console.log(lame);
	///////////////////////////////	
	
    });
    // if you get the 'Left' msg, send an 'l' to the arduino
    	socket.on('Q2', function(data) {
	orient = data.dir;
        console.log('q2');
        serial.write(orient);

	///////////////////////////////
tame = (Date.now()/1000);
lame = tame.toString();
console.log('TIME HERE:');
console.log(lame);
	///////////////////////////////	
	
    });
    // if you get the 'Left' msg, send an 'l' to the arduino
    	socket.on('Q3', function(data) {
	orient = data.dir;
        console.log('q3');
        serial.write(orient);

	///////////////////////////////
tame = (Date.now()/1000);
lame = tame.toString();
console.log('TIME HERE:');
console.log(lame);
	///////////////////////////////	
	
    });
    // if you get the 'Left' msg, send an 'l' to the arduino
    	socket.on('Q4', function(data) {
	orient = data.dir;
        console.log('q4');
        serial.write(orient);

	///////////////////////////////
tame = (Date.now()/1000);
lame = tame.toString();
console.log('TIME HERE:');
console.log(lame);
	///////////////////////////////	
	
    });
    // if you get the 'Left' msg, send an 'l' to the arduino
    	socket.on('Q5', function(data) {
	orient = data.dir;
        console.log('q5');
        serial.write(orient);

	///////////////////////////////
tame = (Date.now()/1000);
lame = tame.toString();
console.log('TIME HERE:');
console.log(lame);
	///////////////////////////////	
	
    });
    // if you get the 'Left' msg, send an 'l' to the arduino
    	socket.on('Q6', function(data) {
	orient = data.dir;
        console.log('q6');
        serial.write(orient);

	///////////////////////////////
tame = (Date.now()/1000);
lame = tame.toString();
console.log('TIME HERE:');
console.log(lame);
	///////////////////////////////	
	
    });
    // if you get the 'Left' msg, send an 'l' to the arduino
    	socket.on('Q7', function(data) {
	orient = data.dir;
        console.log('q7');
        serial.write(orient);

	///////////////////////////////
tame = (Date.now()/1000);
lame = tame.toString();
console.log('TIME HERE:');
console.log(lame);
	///////////////////////////////	
	
    });
    // if you get the 'Left' msg, send an 'l' to the arduino
    	socket.on('Q8', function(data) {
	orient = data.dir;
        console.log('q8');
        serial.write(orient);

	///////////////////////////////
tame = (Date.now()/1000);
lame = tame.toString();
console.log('TIME HERE:');
console.log(lame);
	///////////////////////////////	
	
    });
    // if you get the 'Left' msg, send an 'l' to the arduino
    	socket.on('Q9', function(data) {
	orient = data.dir;
        console.log('q9');
        serial.write(orient);

	///////////////////////////////
tame = (Date.now()/1000);
lame = tame.toString();
	stream.write("TIME HERE: ");
	stream.write(lame);
	stream.write("\n");
console.log('TIME HERE:');
console.log(lame);
	///////////////////////////////	
	
    });
    // if you get the 'Stop' msg, send an 's' to the arduino
    	socket.on('FORWARD', function(data) {
        //console.log('FORWARDs');
	orient = data.dir;
        //console.log('For');
        serial.write(orient);

	///////////////////////////////
tame = (Date.now()/1000);
lame = tame.toString();
console.log('TIME HERE:');
console.log(lame);
	///////////////////////////////	
    });
    // if you get the 'Stop' msg, send an 's' to the arduino
    	socket.on('FF', function(data) {
        //console.log('FORWARDs');
	orient = data.dir;
        //console.log('FF');
        serial.write(orient);

	///////////////////////////////
tame = (Date.now()/1000);
lame = tame.toString();
console.log('TIME HERE:');
console.log(lame);
	///////////////////////////////	

    });

});
//write to the serial port for debugging
serial.on('data',function(data) {
	///////////////////////////////
tame = (Date.now()/1000);
lame = tame.toString();
	///////////////////////////////	
	ardmsg = data.toString();
	//fs.writeFile('message.txt', "   - { TIME HERE:  ", function (err) {
        //if (err) throw err;
	//});
	stream.write("t 	");
	stream.write(lame);	
	stream.write("	a		");
	stream.write(ardmsg);
	stream.write("\n");
  	console.log(ardmsg);
  	console.log("TIME HERE: ");
  	console.log(lame);
});
server.listen(serverPort, function() {
    console.log('listening on *:%s', serverPort);
});
