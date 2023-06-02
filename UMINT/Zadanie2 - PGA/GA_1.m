clearvars;
space = [-10*ones(1,7);10*ones(1,7)];
amp = [-5*ones(1,7);5*ones(1,7)];
hold on;



    Pop=genrpop(50,space);
    for b=1:200
    F=MojaFit1(Pop);      
    theBest = selbest(Pop,F,1);
    bestSel = selbest(Pop,F,[5 3 2]);
    newPop = seltourn(Pop,F,35);
    newPop = mutx(newPop,0.3,space);
    newPop = muta(newPop,0.1,amp,space);
    mixPop = genrpop(5,space);
    Pop = [bestSel;newPop;mixPop];
    
    
    output(b)=MojaFittneska(theBest);
    end
    plot(output);

    
