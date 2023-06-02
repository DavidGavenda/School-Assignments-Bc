
hold on; % podrzi graf aby som vedel potom porovnat

space = [-500*ones(1,5);500*ones(1,5)];
amp = [5*ones(1,10)];
vysledky2=[];

for j = 1:5
    oldPop = genrpop(50,space); %generujem populaciu
    for i = 1:5000
        fit = eggholder(oldPop);     
        bestSel = selbest(oldPop,fit,[4 3 2]);
        theBest = selbest(oldPop,fit,1);
        
        newPop = seltourn(oldPop,fit,30);
        output(i) = eggholder(theBest);

        newPop = crossov(newPop, 2, 1);
        mixPop = genrpop(10,space);
        newPop = mutx(newPop, 0.2, space);
        newPop = muta(newPop,0.1,amp,space);
        oldPop = [theBest;bestSel;newPop;mixPop];
    end

    plot(output);%vypise z matice funkcnych hodnot graf
    vysledky(j)= eggholder(theBest);
    vysledky2=[vysledky2;{theBest}];
end
mean(vysledky)