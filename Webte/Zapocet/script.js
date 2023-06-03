

/* PRVA CAST*/


/* CISTO NA HEADER, ZE DOJDE Z VRCHU  */
gsap.from('header',{ /* OZNACIL SOM SI HEADER */
    duration:1, /* AKO DLHO SA MA VYKONAVAT */
    y:'-100%', /* ORIGINALNA POZICIA, MIMO OBRAZOVKY */
    ease:'bounce' /* EFEKT ODRAZANIA - UKAZ NA STRANKE */
    }
)

/* PRE VSETKY CO MAJU CLASS EXAMPLE */
gsap.from('.example',{
    duration:1, 
    opacity:0, 
    delay:0.5, /* ZACNE MI TO POL SEKUNDY PO NACITANI STRANKY */
    stagger: 0.5, /* KAZDY DALSI S CLASSOM EXAMPLE BUDE TRVAT O POL SEKUNDU DLHSIE, POJDU POSTUPNE */
})

/* OZNACIM SI FOOTER KDE PRE ZMENU VYUZIVAM "TO" NAMIESTO "FROM"*/
gsap.to('footer', {
    duration:2,
    y:0,
    ease:'expo',
})



/* DRUHA CAST */


/* VYUZIVAM AJ "FROM" AJ "TO" DOKOPY "FROMTO" NAJPRV IDE FROM */
gsap.fromTo('#reverse',
    {
        opacity:0,
        rotation:720, 
        scale:0,
    },
    {
        duration:1,
        delay:3.5,
        opacity:1,
        scale:1,
        rotation:0,
    }
)

/* VYUZIVAM DRAGGABLE Z GSAPU */
Draggable.create("#reverse", {
    type:"rotation",
    inertia: true,
});    


/* TRETIA CAST */


function part1() {
    var tl = new TimelineMax();
    tl.to('#box1',5, { x: 50 });
    return tl;
}
  
function part2() {
    var tl = new TimelineMax();
    tl.to('#box2', 3, { x: 100 });
    return tl;
}

function part3() {
    var tl = new TimelineMax();
    tl.to('#box3', 1, { x: 150, rotation: 90 });
    tl.to('#box4', 1, { x: 200, rotation: 180 });
    tl.to('#box5', 1, { x: 250, rotation: 270 });
    return tl;
}
  
var masterTimeline = new TimelineMax({ repeat: -1, repeatDelay: 1 });
masterTimeline
    .add(part1())
    .add(part2(), "+=1")
    .add(part3(), "+=1");

