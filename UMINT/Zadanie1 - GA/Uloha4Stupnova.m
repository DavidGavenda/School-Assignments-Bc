space = [0*ones(1,5);10000000*ones(1,5)];
amp = [-20000 -20000 -20000 -20000 -20000;20000 20000 20000 20000 20000];
nasobnik = [-0.04 -0.07 -0.11 -0.06 -0.05];
nasobnik1 = [0.04 0.07 0.11 0.06 0.05];
PocetJednotlivcov = 50;
PocetGeneracii = 10000;
 
 
 
oldPop = genrpop(PocetJednotlivcov,space);
hold on;
 
for x=1:10
oldPop = genrpop(PocetJednotlivcov,space);
 
for i=1:PocetGeneracii
    oldPopSNasobenim= oldPop .* nasobnik;
    zisk = sum(oldPopSNasobenim,2);
    p=0;
    for j=1:PocetJednotlivcov
        x1 = oldPop(j,1);
        x2 = oldPop(j,2);
        x3 = oldPop(j,3);
        x4 = oldPop(j,4);
        x5 = oldPop(j,5);
 
        if x1+x2+x3+x4+x5 >=10000000 %stupnova pokuta
            p=p+1;
        end
 
        if x1+x2 >=2500000 %stupnova pokuta
            p=p+1;
        end
 
        if -x4+x5 >=0 %stupnova pokuta
            p=p+1; 
        end
 
        if 0.5*(-x1-x2+x3+x4-x5) >=0 %stupnova pokuta
            p=p+1;
        end
        zisk(j)= zisk(j) + 1000000^p;
        p=0;
        
    end
    
    
    zisk = zisk'; %vymenim riadky za stlpce
 
    [po,py] = min(zisk);
    
    theBest = selbest(oldPop,zisk,1);
    bestSel = selbest(oldPop,zisk,[ 5 4 3 2 ]);
    
    newPop = seltourn(oldPop,zisk,30);
    newPop = mutx(newPop,0.3,space);
    newPop = muta(newPop,0.1,amp,space);
    mixPop = genrpop(5,space);
    oldPop = [theBest;bestSel;newPop;mixPop];
 
    output(i)=abs(po);
 
end
 
vysledky(x)= abs(po);
output=output';
rowsToDelete = output < 0 | output > 1000000;
output(rowsToDelete) = [];
plot(output)
end
vysledky
mean(vysledky)


