import random

array = [random.randint(1, 100) for _ in range(10)]
print("Array casuale:", array)

invertito = array[::-1]
print("Array invertito:", invertito)

somma = sum(array)
media = somma / len(array)
print("Somma:", somma)
print("Media:", media)

pari = [x for x in array if x % 2 == 0]
print("Numeri pari:", pari)

dispari = [x for x in array if x % 2 != 0]
print("Numeri dispari:", dispari)

numero = int(input("Inserisci un numero da cercare: "))
if numero in array:
    print("Numero trovato in posizione:", array.index(numero))
else:
    print("Numero non trovato")

da_eliminare = int(input("Inserisci un numero da eliminare: "))
if da_eliminare in array:
    array.remove(da_eliminare)
    print("Nuovo array dopo eliminazione:", array)
else:
    print("Numero da eliminare non trovato")

alternato = array[:]
for i in range(0, len(alternato) - 1, 2):
    alternato[i], alternato[i+1] = alternato[i+1], alternato[i]
print("Array alternato:", alternato)

ordinato = sorted(array)
print("Array ordinato:", ordinato)
