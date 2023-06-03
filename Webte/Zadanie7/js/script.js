// snazil som sa upravit css aj js lightboxu

var i;



$.getJSON("photos.json", function(data){
    for (i in data.photos){
        var thatPart = document.createElement("div");
        thatPart.setAttribute("id",i);
        thatPart.setAttribute("class","item");
        var img = new Image();
        var originalSource = data.photos[i].src;
        originalSource = originalSource.substring(0,originalSource.length-9) + ".jpg";
        thatPart.setAttribute("href","images/" + originalSource);
        thatPart.setAttribute("data-lightbox","myGallery");
        thatPart.setAttribute("data-title",data.photos[i].title + " - " + data.photos[i].description );
        img.src = "images/" + data.photos[i].src;
        img.setAttribute("alt","fotka");
        var searchable = (data.photos[i].title + " " +  data.photos[i].description).toLowerCase();
        thatPart.setAttribute("data-search",searchable);
        thatPart.appendChild(img);
        document.getElementById("gallery").appendChild(thatPart);
    }
})

//THX GOOGLE
jQuery(function($) {
    $.cookie.json = true;
    var list = $.cookie('list')
    var children = $("#gallery").children().each(function(i) {
        $(this).data('number', i) // number the children
    })
    if (list && list.length) { // cookie order
        $.each(list, function(v, i) {
            $("#gallery").append(children.eq(i))
        })
    }
    $("#gallery").sortable({
        update: function(e, ui) {
            var list = $(this).children().map(function() {
                return $(this).data('number')
            }).get()
            $.cookie('list', list) // save new order
        }
    }).disableSelection()
});


$('.search-item').search({
});



