(function() {
    'use strict';
    window.addEventListener('load', function() {
      // Fetch all the forms we want to apply custom Bootstrap validation styles to
      var forms = document.getElementsByClassName('needs-validation');
      // Loop over them and prevent submission
      var validation = Array.prototype.filter.call(forms, function(form) {
        form.addEventListener('submit', function(event) {
          if (form.checkValidity() === false) {
            event.preventDefault();
            event.stopPropagation();
          }
          form.classList.add('was-validated');
        }, false);
      });
    }, false);
})();


function ChangeShip() {
  if (!(document.getElementById('chShipAdd').checked)) {
   document.getElementById('shipadddiv').style.visibility="hidden";
   $(".shipClass").prop("disabled",true);
  }
  else {
  document.getElementById('shipadddiv').style.visibility="visible";
  $(".shipClass").prop("disabled",false);
  }
}

function zobraz() {
  var checkBox = document.getElementById("myCheck");
  var text = document.getElementById("zona");
  if (checkBox.checked == true){
      text.style.display = "block";
  } else {
     text.style.display = "none";
  }
}

var sel1 = document.querySelector('#sel1');
var sel2 = document.querySelector('#sel2');
var options2 = sel2.querySelectorAll('option');

function giveSelection(selValue) {
  sel2.innerHTML = '';
  for(var i = 0; i < options2.length; i++) {
    if(options2[i].dataset.option === selValue) {
      sel2.appendChild(options2[i]);
    }
  }
}

giveSelection(sel1.value);

