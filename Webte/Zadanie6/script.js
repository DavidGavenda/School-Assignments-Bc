//dosadil som pociatocne hodnoty, pretoze ked je to na severy, casto sa zmeska prva suradnica (x = 0)
var sinusX = [0];
var sinusX_old = [];
var sinusTrace;
var dataSinus;
var displaySinus = true;


var cosinusY1 = [0];
var cosinusY2 = [1];
var cosinusY1_old = [];
var cosinusY2_old = [];
var cosinusTrace;
var dataCosinus; 
var displayCosinus = true;  

var updateData = true;
var source;

if(typeof(EventSource) !== "undefined") 
{
  source = new EventSource("http://vmzakova.fei.stuba.sk/sse/sse.php");  
}
else 
{
  document.getElementById("fetchedData").innerHTML = "Sorry, your browser does not support server-sent events...";
}

function fetchData()
{  
  source.addEventListener("message", function(e)
  {
    listenerFunctionContent(e);    
	}); 
}

function listenerFunctionContent(e)
{
  var data = JSON.parse(e.data);
  
  let amplitude = document.querySelector('amplitude-button').getAmplitude();
  if(+data.x == 0)
  {
    cosinusY1[0] = data.y1;
    cosinusY2[0] = data.y2;    
  }
  else
  {
    sinusX.push(data.x);
    cosinusY1.push(data.y1*amplitude);
    cosinusY2.push(data.y2*amplitude);
  }
  
  if(updateData == true)
  {
    drawGraphs();  
  }  
}


function terminator()
{
  updateData = false;
  document.getElementById("terminator").style.display = "none";
  document.getElementById("recovery").style.display = "block";
  
  sinusX_old = sinusX.slice();
  cosinusY1_old = cosinusY1.slice();
  cosinusY2_old = cosinusY2.slice();
}

function recovery()
{
  updateData = true;
  document.getElementById("terminator").style.display = "block";
  document.getElementById("recovery").style.display = "none";
  drawGraphs(); 
}

function toogleSin()
{
  if(displaySinus == true)
  {
    displaySinus = false;
  }
  else
  {
    displaySinus = true;
  } 
  
  drawGraphs();
}

function toogleCos()
{
  if(displayCosinus == true)
  {
    displayCosinus = false;
  }
  else
  {
    displayCosinus = true;
  } 
  drawGraphs();
}


function drawGraphs()
{
  sinusTrace = {
    x: (updateData == true) ? sinusX : sinusX_old,
    y: (updateData == true) ? cosinusY1 : cosinusY1_old,
    line: {
      color: '75DDDD',
      width: 4
    },
    type: 'log',
    name: 'Sinus',
  };
  
  cosinusTrace = {
    x: (updateData == true) ? sinusX : sinusX_old,
    y: (updateData == true) ? cosinusY2 : cosinusY2_old,
    line: {
      color: 'AA3E98' ,
      width: 4
    },
    type: 'log',
    name: 'Cosinus',
  };

  dataSinus = [sinusTrace];
  dataCosinus = [cosinusTrace];
  

  Plotly.newPlot(graph, [], []);     
  
  if(displaySinus == true && displayCosinus == true)
  {
    Plotly.addTraces(graph, dataSinus);
    Plotly.addTraces(graph, dataCosinus);
  }
  else if(displaySinus == true && displayCosinus == false)
  {
    Plotly.addTraces(graph, dataSinus); 
  }
  else if(displaySinus == false && displayCosinus == true)
  {
    Plotly.addTraces(graph, dataCosinus);  
  }  
}
  