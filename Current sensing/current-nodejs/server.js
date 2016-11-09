var express = require('express'); 			// web server application
var http = require('http');				// http basics
var app = express();					// instantiate express server
var server = http.Server(app);				// connects http library to server
var io = require('socket.io')(server);			// connect websocket library to server
var serialport = require('serialport');			// serial library
var serverPort = 8000;
// use express to create the simple webapp
app.use(express.static('public'));		// find pages in public directory

	function gameLoop() {
	console.log('TIME HERE-ARD:');
	console.log(Date.now()/1000);
	}
// check to make sure that the user calls the serial port for the arduino when
// running the server
	if(!process.argv[2]) {
    	console.error('Usage: node '+process.argv[1]+' SERIAL_PORT');
    	process.exit(1);
    }

// start the serial port connection and read on newlines
var serial = new serialport.SerialPort(process.argv[2], {
    parser: serialport.parsers.readline('\r\n')
    });

// this is the websocket event handler and say if someone connects
// as long as someone is connected, listen for messages
io.on('connect', function(socket) {
        console.log('a user connected');

	console.log('TIME START:');
	console.log(Date.now()/1000);

    	socket.on('error', function (err) { 
	console.error(err.stack); // TODO, cleanup 
	});
    
    // if you get the 'Stop' msg, send an 's' to the arduino
    	socket.on('FORWARD', function() {
        //console.log('Stops');
        //serial.write('f');
	console.log('TIME HERE-ARD:');
	console.log(Date.now()/1000);
	
    });s
});

//write to the serial port for debugging
serial.on('data',function(data) {
  console.log(data.toString());
});


server.listen(serverPort, function() {
    //console.log('listening on *:%s', serverPort);
		//while(true){
		//console.log('lopeee');
		setInterval(gameLoop,1000);
});

