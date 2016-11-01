var serialport = require("serialport"),
	portname = process.argv[2]; //for the serial port name from the command line


var myPort = new serialport(portname, { //json object, list of key: value pairs,
	baudRate: 9600,
	options: false, //set customized settings for serial port
	parser: serialport.parsers.readline("\r\n") //parser is in charge of firing serial events; generating data event
});

myPort.on("open", function() {
	console.log("port is open");
});

myPort.on("close", function(){
	console.log("port is closed");
});

myPort.on("error", function() {
	console.log("error error error")
});

myPort.on("data", function(data){ //gets called whenever a new data event occurs
	console.log(data);
	myPort.write('x');
});

