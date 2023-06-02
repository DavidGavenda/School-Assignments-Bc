clearvars;
space = [-10*ones(1,7);10*ones(1,7)];
amp = [-2*ones(1,7);2*ones(1,7)];
%pocet jednotlivcov je 50
%pocet generacii je 1000
%pocet subpopulacii
PoJe = 50;
PoGe = 200;
PoSu = 9;

hold on;
for z=1:PoSu
Pop{z} = genrpop(PoJe,space);
end

for y=1:PoGe
    topky = [];
    for z=1:PoSu
    fit{z} = MojaFit2(Pop{z});
    theBest{z} = selbest(Pop{z},fit{z},1);
    bestSel = selbest(Pop{z},fit{z},[5 3 2]);
    newPop = seltourn(Pop{z},fit{z},35);
    newPop = mutx(newPop,0.3,space);
    newPop = muta(newPop,0.1,amp,space);
    mixPop = genrpop(5,space);
    Pop{z} = [bestSel;newPop;mixPop];
    topky = [topky;theBest{z}];
    end
    
    if mod(y,50)==0
        Pop{1}((randi(48)+2),:)=theBest{9};
        Pop{2}((randi(48)+2),:)=theBest{1};
        Pop{3}((randi(48)+2),:)=theBest{2};
        Pop{4}((randi(48)+2),:)=theBest{3};
        Pop{5}((randi(48)+2),:)=theBest{4};
        Pop{6}((randi(48)+2),:)=theBest{5};
        Pop{7}((randi(48)+2),:)=theBest{6};
        Pop{8}((randi(48)+2),:)=theBest{7};
        Pop{9}((randi(48)+2),:)=theBest{8};
    end
    
    for p=1:PoSu
        output{p}(y)=MojaFittneska(theBest{p});
    end
    

    overFit = MojaFittneska(topky);
    theBestBest = selbest(topky,overFit,1); 
    outputBIG(y)=MojaFittneska(theBestBest);
end
MojaFittneska(theBestBest)


    for p=1:PoSu
        figure(p);
        plot(output{p});
    end
    figure(10);
plot(outputBIG,'k--');
