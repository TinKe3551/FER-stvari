var http = require('http'); // ugrađeni modul, ne treba install
http.createServer(function(req, res) {
console.log(req.url);
res.writeHead(200, { 'Content-Type': 'text/html' }); // header
res.write('Hello World!'); // body
res.end();
}).listen(8000); // sluša na portu 8000