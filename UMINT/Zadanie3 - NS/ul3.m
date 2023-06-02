% importdata('data_letters.txt');
vstup=struct2table(importdata('data_letters.txt'));
inputs=vstup.data;
inputs=inputs';

targets = zeros(26,20000);

lettersInLetters=cell2mat(vstup.textdata); %well, it works 
lettersInNumbers=double(lettersInLetters)-64; %hodim si to aby to boli hodnoty 1-26

for i=1:20000
   targets(lettersInNumbers(i),i) =  1;
end

%matica ziadanych hodnot

pocetNeuronov = 200;
net=patternnet(pocetNeuronov);

net.divideFcn = 'dividerand'; %NAHODNE ROZDELENIE
net.divideParam.trainRatio=0.6;
net.divideParam.testRatio=0.2;
net.divideParam.valRatio = 0.2;

net.trainParam.goal = 0.0000000001;
net.trainParam.show = 25;
net.trainParam.epochs = 500;  	    
net.trainParam.min_grad = 1e-14;


[net, tr] = train( net, inputs,targets );

figure, plotperform(tr)

%Testovanie siete
outputs = net(inputs);
errors=gsubtract(targets,outputs);
performance = perform(net,targets,outputs)

%Vypocita hodnotu chybovej funkcie pre trenovacie, validacne a testovacie
%data
%cez maskovanie zistujeme ich chyby
trainTargets = targets .* tr.trainMask{1};
valTargets = targets .* tr.valMask{1};
testTargets = targets .* tr.testMask{1};
trainPerformance = perform(net,trainTargets,outputs)

valPerformance = perform(net,valTargets,outputs)

testPerformance = perform(net,testTargets,outputs)

[c, cm] = confusion(targets,outputs);

fprintf('Uspesnost klasifikacie : %.4f %%\n' , 100*(1-c));

%Zobrazenie kontingencnej tabulky
figure, plotconfusion(targets,outputs)

% Y = net(inputs);
% classes = vec2ind(Y);
% plotconfusion( outputs, Y );