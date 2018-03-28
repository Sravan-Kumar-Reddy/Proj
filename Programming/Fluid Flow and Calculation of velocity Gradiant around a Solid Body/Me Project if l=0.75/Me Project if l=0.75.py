'''
Group(B1-F):
B.Sravan Kumar Reddy.
B.Sathwik.
K.Surya.
Mayur Gandhi.
Nalluri Pradeep Kumar.
Shivadeep
'''       
import math
x = [0 for i in range(0,59)]
for i in range(0,18):
    x[i] = 0.5*(1.0-1.1**(17-i))

for i in range(18,38):
    x[i] = 0.05*(i-17)
    
for i in range(38,59):
    x[i] = 1.0-0.5*(1-(1.1)**(i-37))
y = [0 for j in range(0,60)]
for j in range(0,27):
    y[j] = -0.15+0.5*(1-1.1**(26-j))

for j in range(26,34):
    if j <= 29 :
        y[j] = 0.05*(j-29)
    elif j == 30 :
        y[j] = y[j-1]
    elif j > 30:
        y[j] = 0.05*(j-30)
    
for j in range(33,60):
    y[j] = 0.15-0.5*(1-1.1**(j-33))
     
H = [0 for i in range(0,59)]
for i in range(1,58):
    H[i] = (x[i+1] - x[i-1])*0.5

K = [0 for j in range(0,60)]
for j in range(1,29):
    K[j] = (y[j+1]-y[j-1])*0.5

for j in range(31,59):
    K[j] = (y[j+1]-y[j-1])*0.5

K[29] = (y[29+2]-y[29-1])*0.5   
K[30] = (y[30+1]-y[30-2])*0.5
p = [[0 for j in range(0,len(y))] for i in range(0,len(x))]
s = [[0 for j in range(0,len(y))] for i in range(0,len(x))]
p_new = [[0 for j in range(0,len(y))] for i in range(0,len(x))]


count = 0
e = 0.001
w = 1.2
angle = (math.pi/180)*4
v_in = 90



while True:
    count+=1
    for i in range(1,58):
        for j in range(1,59):
            if (i==1)and(j==1):
                k = K[j]
                h = H[i]
                p[i][j] = (k*k*(s[i+1][j])+h*h*(s[i][j+1]))/(h*h+k*k)  #NN2
            
            if (i==1)and(j==58):
                k = K[j]
                h = H[i]
                p[i][j] = (k*k*(s[i+1][j])+h*h*(p[i][j-1]))/(h*h+k*k)  #NN3
            
            if (i==57)and(j==58):
                k = K[j]
                h = H[i]
                p[i][j] = (k*k*(p[i-1][j])+h*h*(p[i][j-1]))/(h*h+k*k)  #NN4
    
            if(i==57)and(j==1):
                k = K[j]
                h = H[i]
                p[i][j] = (k*k*(p[i-1][j])+h*h*(s[i][j+1]))/(h*h+k*k)  #NN5
            #for points like E
            ###################NN6            
            if(j>1)and(j<59)and(i==1)and(j!=29)and(j!=30):
                k = K[j]
                h = H[i]
                p[i][j]= (k*k*(s[i+1][j])+h*h*(s[i][j+1]+p[i][j-1]))/(2*h*h+k*k) #NN6
            #for points like F
            ##################NN7    
            if(i>1)and(i<58)and(j==58):
                k = K[j]
                h = H[i]
                p[i][j] = (k*k*(s[i+1][j]+p[i-1][j])+h*h*p[i][j-1])/(h*h+2*k*k) #NN7
             #for points like G
            ##################NN8   
            if(i==57)and(j>1)and(j<59):
                k = K[j]
                h = H[i]
                p[i][j] = (k*k*p[i-1][j]+h*h*(s[i][j+1]+p[i][j-1]))/(2*h*h+k*k)  #NN8
            #for points like H
            #################NN9    
            if(i>1)and(i<58)and(j==1):
                k = K[j]
                h = H[i]
                p[i][j] = (k*k*(s[i+1][j]+p[i-1][j])+h*h*s[i][j+1])/(h*h+2*k*k)  #NN9
            ##NN21
            #for J2               
            if(i>1)and(i<17)and(j==29):
                k = K[j]
                h = H[i]
                p[i][j] = (k*k*(s[i+1][j]+p[i-1][j])+h*h*(s[i][j+2]+p[i][j-1]))/2*(h*h +k*k) #NN21
#            ##NN22
#            ##for I2      
            if(i>1)and(i<17)and(j==30):
                k = K[j]
                h = H[i]
                p[i][j] = p[i][j-1]    #NN22
#            ##NN23
#            ##for E    
            if(i==1)and(j==29):
                k = K[j]
                h = H[i]
                p[i][j] = (k*k*s[i+1][j]+h*h*(s[i][j+2]+p[i][j-1]))/(2*h*h+k*k) #NN23

            if(i>1)and(i<57)and(((j>1)and(j<28))or((j>31)and(j<58))):
                k = K[j]
                h = H[i]
                p[i][j] = (k*k*(s[i+1][j]+p[i-1][j]) + h*h*(s[i][j+1]+p[i][j-1]))/2*(h*h+k*k) #NN1

            if(i>1)and(i<17)and((j==28)or(j==31)):
                k = K[j]
                h = H[i]
                p[i][j] = (k*k*(s[i+1][j]+p[i-1][j]) + h*h*(s[i][j+1]+p[i][j-1]))/2*(h*h+k*k) #NN1

    for i in range(17,58):
        for j in range(1,59):
            #for points like I_dash
            ###############NN11    
            if(i>=17)and(i<=37)and(j==31):
                k = K[j]
                h = H[i]
                p[i][j] = (k*k*(s[i+1][j]+p[i-1][j])+h*h*(s[i][j+1]+k*v_in*math.sin(angle)))/(h*h+2*k*k)  #NN11
            #for points like J_dash
            ###############NN13            
            if(i>=17)and(i<=37)and(j==28):
                k = K[j]
                h = H[i]
                p[i][j] = (k*k*(s[i+1][j]+p[i-1][j])+h*h*(s[i][j-1]-k*v_in*math.sin(angle)))/(h*h+2*k*k)  #NN13
#            ##For points like I1_dash
#            #####NN15    
            if(i>37)and(j==31):
                k = K[j]
                h = H[i]
                if x[i]<1.06:
                    l=0.75
                else:
                    l=0
                p[i][j] = (k*k*(s[i+1][j]+p[i-1][j])+h*h*(s[i][j+1]+k*l*v_in*math.sin(angle)))/(h*h+2*k*k) #NN15
#            ##For points like J1_dash
#            ########NN16  
            if(i>37)and(j==28):
                k = K[j]
                h = H[i]
                if x[i]<1.06:
                    l=0.75
                else:
                    l=0
                p[i][j] = (k*k*(s[i+1][j]+p[i-1][j])+h*h*(s[i][j-1]-k*l*v_in*math.sin(angle)))/(h*h+2*k*k) #NN16
#            ##NNN17
#            # For Points next to I1_dash like G            
            if(i==57)and(j==31):
                k = K[j]
                h = H[i]  
                if x[i]<1.06:
                    l=0.75
                else:
                    l=0
                p[i][j] =(k*k*p[i-1][j]+(h*h*(s[i][j+1]+k*l*v_in*math.sin(angle))))/(h*h+k*k) #NN17
            ##NN18
            # For Points next to J1_dash like G    
            if(i==57)and(j==28):
                k = K[j]
                h = H[i]
                if x[i]<1.06:
                    l=0.75
                else:
                    l=0
                p[i][j] = (k*k*(p[i-1][j])+(h*h*(s[i][j-1]-k*l*v_in*math.sin(angle))))/(h*h+k*k) #NN18 
    for i in range(17,58):
        for j in range(29,31):
            #for points like I
            ###############NN10    
            if(i>=17)and(i<=37)and(j==30):
                k = K[j]
                h = H[i]
                p[i][j] = p[i][j+1]+k*v_in*math.sin(angle)    #NN10
            #for points like J
            ###############NN12    
            if(i>=17)and(i<=37)and(j==29):
                k = K[j]
                h = H[i]
                p[i][j] = p[i][j-1]-k*v_in*math.sin(angle)   #NN12            
             ##NN19
           ##For points I1    
            if(i>37)and(j==30):
                k = K[j]
                h = H[i]
                if x[i]<1.06:
                    l=0.75
                else:
                    l=0
                p[i][j-1] = p[i][j]+ k*l*v_in*math.sin(angle) #NN19  
            #            ##NN20
#            ##For points like J1    
            if(i>37)and(j==29):
                k = K[j]
                h = H[i]
                if x[i]<1.06:
                    l=0.75
                else:
                    l=0
                p[i][j+1]  = p[i][j] - k*l*v_in*math.sin(angle) #NN20


    for j in range(1,59):
        for i in range(1,58):
            p_new[i][j] = w*p[i][j] + (1-w)*s[i][j]


    lll = []
    for j in range(1,59):
        for i in range(1,58):
            a = abs(p_new[i][j] - s[i][j])
            lll.append(a)
    s[i][j] = p[i][j]
    p_new[i][j] = p[i][j]      
    if max(lll)<e:
        break
    else:
        for j in range(1,59):
            for i in range(1,58):
                s[i][j] = p[i][j]
                p[i][j] = p_new[i][j]
#on the upper side of plate
Vu = [0 for i in range(17,38)]  
Vu[0] = v_in*math.cos(angle) + (p[17+1][30]-p[17][30])/(x[17+1]-x[17])
Vu[20] = v_in*math.cos(angle) + (p[37][30]-p[37-1][30])/(x[37]-x[37-1])
for i in range(18,37):
    Vu[i-17] = v_in*math.cos(angle)+  (p[i+1][30]-p[i-1][30])/(x[i+1]-x[i-1])


#V for the lower side of the 
Vl = [0 for i in range(17,38)]
Vl[0] = v_in*math.cos(angle) + (p[17+1][29]-p[17][29])/(x[17+1]-x[17])
Vl[20] = v_in*math.cos(angle) + (p[37][29]-p[37-1][29])/(x[37]-x[37-1])
for i in range(18,37):
    Vl[i-17] = v_in*math.cos(angle) +  (p[i+1][29]-p[i-1][29])/(x[i+1]-x[i-1])

 
cpl=[]#cp for lower part of plate
for i in Vl:
    cpe=1-(i/v_in)**2
    cpl.append(cpe)
cpu=[]#cp for upper part of plate
for i in Vu:
    cpe=1-(i/v_in)**2
    cpu.append(cpe)
a=0#c lift
for i in range(0,21):
    a=a+(cpl[i]-cpu[i])*H[i]
cle=a/(1.05*(x[37]-x[17]))
X=[x[i] for i in range(17,38)]
import numpy as np
import matplotlib.pyplot as plt
plt.figure(1)
plt.plot(X,Vu,'r-')
plt.title('V vs X')

plt.figure(1)
plt.plot(X,Vl,'b-')
plt.legend(['Vu vs X', 'Vl vs X'])

plt.show()

plt.figure(2)
plt.plot(X,cpl,'g-')

plt.figure(2)
plt.plot(X,cpu)
plt.legend(['cpl vs X', 'cpu vs X'])
plt.title('Cp vs Y')
plt.show()
delta_cp=[]
for i  in range(0,21):
    delta_cp.append(cpu[i]-cpl[i])

plt.figure(3)
plt.plot(X,delta_cp)
plt.show()
plt.title('delta_cp vs X')
