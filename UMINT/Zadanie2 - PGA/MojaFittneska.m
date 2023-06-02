% Funkcia


function[Fit]=MojaFittneska(Pop)

global evals

[lpop,lstring]=size(Pop);

for i=1:lpop

    x=Pop(i,:);

    Fit(i) = 0;

    for j=1:(lstring-1)
        Fit(i) = ((Pop(i,1)-10)^2+ 5*(Pop(i,2)-12)^2 + Pop(i,3)^4 + 3*(Pop(i,4)-11)^2 + 10*Pop(i,5)^6 + 7*Pop(i,6)^2 + Pop(i,7)^4 - 4*Pop(i,6)*Pop(i,7) - 10*Pop(i,6) - 8*Pop(i,7));
    end;

    %evals=evals+1;
end;


