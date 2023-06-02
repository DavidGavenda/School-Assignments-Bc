clearvars
hold on; % podrzi graf aby som vedel potom porovnat

space = [-500*ones(1,5);500*ones(1,5)];
amp = [5*ones(1,10)];
vysledky2=[];


for j = 1:5
    oldPop1 = genrpop(50,space); %generujem populaciu
    oldPop2 = genrpop(50,space);
    oldPop3 = genrpop(50,space);
    oldPop4 = genrpop(50,space);
    oldPop5 = genrpop(50,space);
    for i = 1:5000
        fit1 = eggholder(oldPop1);     
        bestSel1 = selbest(oldPop1,fit1,[4 3 2]);
        theBest1 = selbest(oldPop1,fit1,1); 
        newPop1 = seltourn(oldPop1,fit1,30);
        newPop1 = crossov(newPop1, 2, 1);
        mixPop1 = genrpop(10,space);
        newPop1 = mutx(newPop1, 0.2, space);
        newPop1 = muta(newPop1,0.1,amp,space);
        oldPop1 = [theBest1;bestSel1;newPop1;mixPop1];
        
        fit2 = eggholder(oldPop2);     
        bestSel2 = selbest(oldPop2,fit2,[4 3 2]);
        theBest2 = selbest(oldPop2,fit2,1); 
        newPop2 = seltourn(oldPop2,fit2,30);
        newPop2 = crossov(newPop2, 2, 1);
        mixPop2 = genrpop(10,space);
        newPop2 = mutx(newPop2, 0.2, space);
        newPop2 = muta(newPop2,0.1,amp,space);
        oldPop2 = [theBest2;bestSel2;newPop2;mixPop2];
    
        fit3 = eggholder(oldPop3);     
        bestSel3 = selbest(oldPop3,fit3,[4 3 2]);
        theBest3 = selbest(oldPop3,fit3,1); 
        newPop3 = seltourn(oldPop3,fit3,30);
        newPop3 = crossov(newPop3, 2, 1);
        mixPop3 = genrpop(10,space);
        newPop3 = mutx(newPop3, 0.2, space);
        newPop3 = muta(newPop3,0.1,amp,space);
        oldPop3 = [theBest3;bestSel3;newPop3;mixPop3];
        
        fit4 = eggholder(oldPop4);     
        bestSel4 = selbest(oldPop4,fit4,[4 3 2]);
        theBest4 = selbest(oldPop4,fit4,1); 
        newPop4 = seltourn(oldPop4,fit4,30);
        newPop4 = crossov(newPop4, 2, 1);
        mixPop4 = genrpop(10,space);
        newPop4 = mutx(newPop4, 0.2, space);
        newPop4 = muta(newPop4,0.1,amp,space);
        oldPop4 = [theBest4;bestSel4;newPop4;mixPop4];
        
        fit5 = eggholder(oldPop5);     
        bestSel5 = selbest(oldPop5,fit5,[4 3 2]);
        theBest5 = selbest(oldPop5,fit5,1); 
        newPop5 = seltourn(oldPop5,fit5,30);
        newPop5 = crossov(newPop5, 2, 1);
        mixPop5 = genrpop(10,space);
        newPop5 = mutx(newPop5, 0.2, space);
        newPop5 = muta(newPop5,0.1,amp,space);
        oldPop5 = [theBest5;bestSel5;newPop5;mixPop5];
        
        %migracia D
        
        if mod(i,50)==0
            oldPop1((randi(48)+2),:)=theBest5;
            oldPop2((randi(48)+2),:)=theBest1;
            oldPop3((randi(48)+2),:)=theBest2;
            oldPop4((randi(48)+2),:)=theBest3;
            oldPop5((randi(48)+2),:)=theBest4;
        end
            
        
        totalPop=[oldPop1;oldPop2;oldPop3;oldPop4;oldPop5];
        fitTotal=eggholder(totalPop);
        theBest = selbest(totalPop,fitTotal,1);
        
        output(i)=eggholder(theBest);
    
    
    
    
    
    end

    plot(output);%vypise z matice funkcnych hodnot graf
    vysledky(j)= eggholder(theBest);
    %vysledky2=[vysledky2;{theBest1}];
end
mean(vysledky)