import os
import time
import random


def gensachovnicu(n):                                           #GENEROVANIE DOSKY
    global S,p,b,r
    b=int((n-1)/2+1)                                            #stredny bod
    r=int((n-1)/2)                                              #dlzka ramena          
    S=[[0 for x in range(n+1)]for y in range(n+1)]
    for x in range(n+1):
        for y in range(n+1):
            S[x][y]=" "                                         #vsetkemu priradim prazdno, tam kde potrebujem,zmenim hodnotu
            if x!=1 and x!=n and x!=b and x!=(b+1) and x!=(b-1):#medzi riadky
                if y==b:
                    S[x][y]="D"
                if y==(b+1) or y==(b-1):
                    S[x][y]="*"                                 #medzi riadky.
            if x==0:                                            #cislovanie stlpcov
                for i in range(n+1):
                    S[x][x+i]=(i-1)%10
            S[0][0]=" "
            if x==1 or x==(n):                                  #prvy a posledny riadok
                S[x][b-1]="*"
                S[x][b]="*"
                S[x][b+1]="*"                                   #prvy a posledny riadok.
            if x==b:                                            #stredny riadok
                S[x][y]="D"
            if x==b and (y==1 or y==n):
                S[x][y]="*"
            S[b][b]="X"                                         #stredny.
            if x==(b-1) or x==(b+1):                            #nad a pod strednym riadkom
                S[x][y]="*" 
                if y==b:
                    S[x][y]="D"                                 #nad a pod strednym riadkom.           
            if x>1 and y==0:                                    #cislovanie riadkov                                
                S[x][y]=(x-1)%10
            S[1][0]=0
            S[b-1][b]="D"
    return S
def vypis(S):                                                   #VYKRESLENIE DOSKY POCIATOCNEJ
    for x in range(n+1):
        for y in range(n+1):
            print(S[x][y],end=" ")
        print()
def draha(n,S):
    b=int((n-1)/2+1) 
    p=(int((n-1)*4))
    r=(int((n-1)/2))
    i=0
    j=0
    global HX,HY
    HX=[[0 for a in range(p+r)]for b in range(p+r)]              #Z bodov, kde sa nachadza * si spravim dve polia, ktore spolu koreluju aby som ziskal drahu, suradnice X a Y, a aj tie su dvojrozmerne aby som mal pre oboch hracov
    HY=[[0 for a in range(p+r)]for b in range(p+r)]
    for x in range(1,b+1):                                          #Draha pre hraca A, postupne som nacitaval body "*" v spravnom poradi, v akom sa ma panacik pohybovat
        for y in range(b+1,n+1):                
            if S[x][y]=="*":
                HX[i][0]=x
                HY[i][0]=y
                i=i+1
    for x in range(b+1,n+1):
        for y in range(n,b,-1):
            if S[x][y]=="*":
                HX[i][0]=x
                HY[i][0]=y
                i=i+1
    for x in range(n,b,-1):
        for y in range(b,0,-1):
            if S[x][y]=="*":
                HX[i][0]=x
                HY[i][0]=y
                i=i+1
    for x in range(b,0,-1):
        for y in range(0,b+1):
            if S[x][y]=="*":
                HX[i][0]=x
                HY[i][0]=y
                i=i+1
    for x in range(b):
        if S[x][y]=="D":
            HX[i][0]=x
            HY[i][0]=y
            i=i+1

            
    for x in range(n,b,-1):                                     #Draha pre hraca B,to iste
        for y in range(b-1,0,-1):
            if S[x][y]=="*":
                HX[j][1]=x
                HY[j][1]=y
                j=j+1
    for x in range(b,0,-1):
        for y in range(0,b+1):
            if S[x][y]=="*":
                HX[j][1]=x
                HY[j][1]=y
                j=j+1
    for x in range(1,b+1):
        for y in range(b+1,n+1):
            if S[x][y]=="*":
                HX[j][1]=x
                HY[j][1]=y
                j=j+1
    for x in range(b+1,n+1):
        for y in range(n,b-1,-1):
            if S[x][y]=="*":
                HX[j][1]=x
                HY[j][1]=y
                j=j+1
    for x in range(n,b,-1):
        if S[x][y]=="D":
            HX[j][1]=x
            HY[j][1]=y
            j=j+1

            

    return HX,HY,p,r
def pohybA(c,S,HX,HY,d):                                      #Pohyb pre panacika A
    if d+c>int((n-1)*4+((n-3)/2)):
        return False 
    if S[HX[d+c][0]][HY[d+c][0]]=="*" or S[HX[d+c][0]][HY[d+c][0]]=="D" or S[HX[d+c][0]][HY[d+c][0]]=="B":      #Staci dat else ale co uz
        return True
 

def pohybB(c,S,HX,HY,k):                                      #Pohyb pre panacika B
    if k+c>int((n-1)*4+((n-3)/2)):
        return False
    if S[HX[k+c][1]][HY[k+c][1]]=="*" or S[HX[k+c][1]][HY[k+c][1]]=="D" or S[HX[k+c][1]][HY[k+c][1]]=="A" :     #Staci dat else ale toto vyzera viac cool
        return True

def novaA(n,S,HX,HY,d):                                         #Funkcia, ktora vytvara na zaciatku hry noveho panacika
    c=random.randint(1,6)
    if c==6:
        print("A: Kocka ukazuje",c)
        S[1][b+1]="A"
        return True
    else:
        print("A: Kocka ukazuje",c)
        c=random.randint(1,6)
        if c==6:
            print("A: Kocka ukazuje",c)
            S[1][b+1]="A"
            return True
        else:
            print("A: Kocka ukazuje",c)
            c=random.randint(1,6)
            if c==6:
                print("A: Kocka ukazuje",c)
                S[1][b+1]="A"
                return True
            else:
                print("A: Kocka ukazuje",c)
                print("A: Dosli ti tri hody")
                return False
                
def novaB(n,S,HX,HY,k):
    c=random.randint(1,6)
    if c==6:
        print("B: Kocka ukazuje",c)
        S[n][b-1]="B"
        return True
    else:
        print("B: Kocka ukazuje",c)
        c=random.randint(1,6)
        if c==6:
            print("B: Kocka ukazuje",c)
            S[n][b-1]="B"
            return True
        else:
            print("B: Kocka ukazuje",c)
            c=random.randint(1,6)
            if c==6:
                print("B: Kocka ukazuje",c)
                S[n][b-1]="B"
                return True
            else:
                print("B: Kocka ukazuje",c)
                print("B: Dosli ti tri hody")
                return False

def HRA(n,S,HX,HY):
    d,k,i,j=0,0,0,0

    while i!=(int((n-3)/2)) and j!=(int((n-3)/2)):
        for x in range(2,n):                                                                                                #Pokial sa panacik hybe v domceku a predosla poloha bola hviezdicka aby sa aj tak zmenila na domcek
            if S[x][int((n-1)/2+1)]=="*":
                S[x][int((n-1)/2+1)]="D"

                
        if d!=0:                                                                                                            #Samotny pohyb hraca A, ktory funguje podla toho ci hrac moze ist alebo nie
            c=random.randint(1,6)
            print("A: Kocka ukazuje",c)

            if pohybA(c,S,HX,HY,d)==True and S[HX[d+c][0]][HY[d+c][0]]=="D":
                S[HX[d+c][0]][HY[d+c][0]]="A"
                S[HX[d][0]][HY[d][0]]="*"
                i=i+1
                d=0
            elif pohybA(c,S,HX,HY,d)==True and S[HX[d+c][0]][HY[d+c][0]]!="A":
                if S[HX[d+c][0]][HY[d+c][0]]=="B":                                                                          #vyhadzovanie superovych panacikov
                    print("A:CHA,vyhodil si superovi panacika")
                    k=0
                S[HX[d+c][0]][HY[d+c][0]]="A"
                S[HX[d][0]][HY[d][0]]="*"
                d=d+c

            
        if k!=0:                                                                                                            #To iste ale pre hraca B
            c=random.randint(1,6)
            print("B: Kocka ukazuje",c)

            if pohybB(c,S,HX,HY,k)==True and S[HX[k+c][1]][HY[k+c][1]]=="D":
                S[HX[k+c][1]][HY[k+c][1]]="B"
                S[HX[k][1]][HY[k][1]]="*"
                k=k+c
                j=j+1
                k=0
            elif pohybB(c,S,HX,HY,k)==True and S[HX[k+c][1]][HY[k+c][1]]!="B":
                if S[HX[k+c][1]][HY[k+c][1]]=="A":                                                                          #vyhadzovanie superovych panacikov
                    print("B:CHA,vyhodil si superovi panacika")
                    d=0
                S[HX[k+c][1]][HY[k+c][1]]="B"
                S[HX[k][1]][HY[k][1]]="*"
                k=k+c
            

        if d==0 and i!=(int((n-3)/2)):                                                                                                            #Tvorba noveho panacika pre A
            if novaA(n,S,HX,HY,d)==True:
                c=random.randint(1,6)
                print("A: Kocka ukazuje",c)
                S[HX[d+c][0]][HY[d+c][0]]="A"
                S[HX[d][0]][HY[d][0]]="*"
                d=d+c
                        
        if k==0 and j!=(int((n-3)/2)):                                                                                                            #Tvorba noveho panacika pre B
            if novaB(n,S,HX,HY,k)==True:
                c=random.randint(1,6)
                print("B: Kocka ukazuje",c)
                S[HX[k+c][1]][HY[k+c][1]]="B"
                S[HX[k][1]][HY[k][1]]="*"
                k=k+c


                            
        if i==(int((n-3)/2)):                                                                                               #Kontrola na to,ci ma hrac vsetkych panacikov v domceku.Ak ano,vyhral
            print("Gratulujem vyhral hrac A")
            vypis(S)
            time.sleep(5)
            break
        if j==(int((n-3)/2)):
            print("Gratulujem vyhral hrac B")
            vypis(S)
            time.sleep(5)
            break


        vypis(S)
        time.sleep(1)
        os.system('cls')
    



print("Zadaj aku velku sachovnicu chces")                       #zistovanie velkosti a kontrola
n=int(input())
while n<5 or n%2==0:
    print("Zadaj aku velku sachovnicu chces")
    n=int(input())                                              #zistovanie velkosti a kontrola.
os.system('cls')
gensachovnicu(n)
print("TOTO JE SACHOVNICA, KTORA BOLA VYTVORENA")
vypis(S)
draha(n,S)
HRA(n,S,HX,HY)

        
