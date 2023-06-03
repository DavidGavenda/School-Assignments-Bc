var isXValid = false;
var isYValid = false;

function validX(inputTxt){
    var xErrorField = document.getElementById("xErrorField");
    var x = document.getElementById("x").value;
    if(x==""){
        xErrorField.textContent="Číslo X musíš zadať";
        isXValid = false;
    }
    else if(x<1){
        xErrorField.textContent="Číslo X je príliš malé";
        isXValid = false;
    }
    else if(x>9){
        xErrorField.textContent="Číslo X je príliš veľké";
        isXValid = false;
    }
    else{
        xErrorField.textContent="";
        isXValid = true;
    }
}

function validY(inputTxt){
    var yErrorField = document.getElementById("yErrorField");
    var y = document.getElementById("y").value;
    if(y==""){
        yErrorField.textContent="Číslo Y musíš zadať";
        isYValid = false;
    }
    else if(y<1){
        yErrorField.textContent="Číslo Y je príliš malé";
        isYValid = false;
    }
    else if(y>9){
        yErrorField.textContent="Číslo Y je príliš veľké";
        isYValid = false;
    }
    else{
        yErrorField.textContent="";
        isYValid = true;
    }
}

function validateForm(){
    if(isXValid&&isYValid){
        generateTable();
        openModal();
        return true;
    }
    else {
        console.log("POPO");
        return false;
    }
}

function generateTable(){


    var table = document.createElement("table");
    var x = document.getElementById("x").value;
    var y = document.getElementById("y").value;
    var divtab = document.createElement("div");
 
    console.log(x + " " + y);

    for(var rowIndex = 0;rowIndex<=y;rowIndex++){
        var tr = document.createElement("tr");
        for(var colIndex = 1 ; (colIndex-1)<=x; colIndex++){
            var td = document.createElement("td");
            if(colIndex==1){
                if(rowIndex==0){
                    var text = document.createTextNode("    ");
                    td.appendChild(text);
                }
                else{
                    var text = document.createTextNode("Y = " + rowIndex + "  ");
                    td.appendChild(text);
                }
            }
            else if(rowIndex==0){
                var text = document.createTextNode("X = " + (colIndex-1) + "  ");
                td.appendChild(text);
            }
            else{
                var text = document.createTextNode((colIndex-1) * rowIndex);
                td.appendChild(text);
            }
            
            tr.appendChild(td);
        }
        table.appendChild(tr);
    }
    divtab.appendChild(table);

    table.setAttribute("class","table");
    divtab.setAttribute("id","divtab")

    var existujuciElement = document.getElementById("TBL");
    existujuciElement.appendChild(divtab);
}


function deleteTable(){
    var table = document.getElementById("divtab");
    table.remove();
}


// THX GOOGLE
function openModal() {
    document.getElementById("backdrop").style.display = "block"
    document.getElementById("tableModal").style.display = "block"
    document.getElementById("tableModal").className += "show"
}
function closeModal() {
    deleteTable();
    document.getElementById("backdrop").style.display = "none"
    document.getElementById("tableModal").style.display = "none"
    document.getElementById("tableModal").className += document.getElementById("tableModal").className.replace("show", "")
}

var modal = document.getElementById('tableModal');

window.onclick = function (event) {
    if (event.target == modal) {
        closeModal()
    }
}


