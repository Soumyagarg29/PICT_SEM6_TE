
import random
def isPrime(n):
    if n==1 :
        return False
    elif n<=3:
        return True
    
    elif n%2==0 or n%3==0:
        return False
    
    i=5
    while i*i<=n:
        if(n%i==0 or n%(i+2)==0):
            return False
        i+=6

    return True


def mod_inv(a , m):
    m0 , x0 , x1 = m , 0, 1
    while a >1:
        q = a//m
        m , a = a%m , m
        x0 , x1 = x1 - q  * x0 , x0
    return x1 + m0 if x1<x0 else x0


def gcd(a , b):
     
    while (b!=0):
        a , b = b , a%b
    return a 



def key_genrate(p , q):
    n = p*q
    phin = (p-1) * (q-1)

    e = random.randrange(1 , phin)
    while(gcd(e , phin) != 1):
        e = random.randrange(1 , phin)

    # d = mod_inv(e , phin)
    d = pow(e , -1 , phin)

    return ((e,n) , (d , n))



def encrypt(message , public_key):
    
    e, n = public_key
    encryp_msg = [pow(ord(char) , e , n) for char in message]
    return encryp_msg
    


def decrypt(ciphertext , private_key):

    d , n = private_key
    plain_text = [chr(pow(char , d , n)) for char in ciphertext]
    return ''.join(plain_text)



msg = input("Enter message : ")


p = int(input("Enter prime no p : "))
q = int(input("Enter prime no q : "))

public_key , private_key = key_genrate(p, q)


cipher = encrypt(msg , public_key)
print("Cipher text : " , cipher)
pt = decrypt(cipher , private_key)


print("Plain Text : " , pt)
  
    