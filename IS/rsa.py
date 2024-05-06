import math
import random
'''
Theory for RSA - Asymmetric Key Cryptography algos :
1.Select large prime numbers p and q
2. n = p*q  and phiN =  (p-1)*(q-1)
3. Select e such that 1<e<phiN and gcd(e , phiN) = 1
4. Calculate d such that d = e^-1 mod phiN
5. Public key = (e , n) , Private key = (d , n)
6. Encryption: c = m^e mod n
7. Decryption: m = c^d mod n
8. Security: n should be large enough to prevent brute force attacks
9. Security: e should be large enough to prevent factorization attacks
'''

def is_prime(n : int):

    if n<=1 :
        return False
    if n<=3:
        return True
    if n%2==0 or n%3==0:
        return False
    
    for i in range (5 , int(math.sqrt(n) + 1) , 6):
        if n%i==0 or n%(i+2)==0:
            return False

    return True

def gcd(a , b):
    if(a==0):
        return b
    return gcd(b%a , a)


def modinv(a , m): #d = e^-1 mod phiN
    ''' The modular inverse of a number  a modulo m is another number x such that:(a×x)modm=1
(a * x)modm=1. In other words, it's a number that when multiplied by a and then taken modulo m, results in 1.
'''
    m0, x0, x1 = m, 0, 1
    while a > 1:
        q = a // m
        m, a = a % m, m
        x0, x1 = x1 - q * x0, x0
    return x1 + m0 if x1 < 0 else x1

    
def generate_keypair(p , q):
    n=p*q
    phiN = (p-1) * (q-1)

    e = random.randrange(1 , phiN)
    while(gcd(e , phiN)!=1): #e should be coprime with phiN
        e = random.randrange(1 , phiN)

    d = modinv(e , phiN)
    
    return ((e , n) , (d , n))


def encrypt(public_key , message): #c = m^e mod n
    e, n = public_key
    encrypted_message=[pow(ord(char) , e , n) for char in message]  
    return encrypted_message

def decrypt(private_key , message): #m = c^d mod n
    d, n = private_key
    decrypted_message = [chr(pow(char , d , n)) for char in message]
    return ''.join(decrypted_message)


if __name__ == '__main__':

    print("RSA Encryption and Decryption")
    print("=============================")


    while(True):
        p = int(input("Enter p: "))
        if is_prime(p):
            break
    while(True):
        q = int(input("Enter q: "))
        if is_prime(q):
            break
    
    public_key , private_key = generate_keypair(p , q)
    print("Public key: " , public_key)
    print("Private key",private_key)

    message = input("Enter the message: ")
    print("Message: " , message)

    encrypted_message = encrypt(public_key , message)
    for (x, y) in zip(encrypted_message , message):
        print(x  , ' - ' , y)
    # print("Encrypted message: " , ''.join(map(lambda x: str(x) , encrypted_message)))

    decrypted_message = decrypt(private_key , encrypted_message)
    print("Decrypted message: " , decrypted_message)
