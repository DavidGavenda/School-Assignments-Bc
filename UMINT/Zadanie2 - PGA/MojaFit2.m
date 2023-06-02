% Funkcia


function[Fit]=MojaFit2(Pop)

global evals

[lpop,lstring]=size(Pop);

for i=1:lpop

    x=Pop(i,:);

    Fit(i) = 0;

    for j=1:(lstring-1)
        pokuta=0;
        Fit(i) = (Pop(i,1)-10)^2+ 5*(Pop(i,2)-12)^2 + Pop(i,3)^4 + 3*(Pop(i,4)-11)^2 + 10*Pop(i,5)^6 + 7*Pop(i,6)^2 + Pop(i,7)^4 - 4*Pop(i,6)*Pop(i,7) - 10*Pop(i,6) - 8*Pop(i,7);
            
        podm1=127-2*Pop(i,1)^2-3*Pop(i,2)^4-Pop(i,3)-4*Pop(i,4)^2-5*Pop(i,5);
        if (podm1<0)
            pokuta=pokuta+1;
        end

        %Podmienka 2
        podm2=282-7*Pop(i,1)-3*Pop(i,2)-10*Pop(i,3)^2-Pop(i,4)+Pop(i,5);
        if (podm2 < 0)
            pokuta=pokuta+1;
        end

        %Podmienka 3
        podm3=196-23*Pop(i,1)-Pop(i,2)^2-6*Pop(i,6)^2+8*Pop(i,7);
        if (podm3 < 0)
            pokuta=pokuta+1;
        end

        %Podmienka 4
        podm4=-4*Pop(i,1)^2-Pop(i,2)^2-3*Pop(i,1)*Pop(i,2)-2*Pop(i,3)^2-5*Pop(i,6)+11*Pop(i,7);
        if (podm4 < 0)
            pokuta=pokuta+1;
        end
        
        if pokuta>0
        Fit(i)=Fit(i)+10^4*pokuta;
        end

    end

    %evals=evals+1;
end



