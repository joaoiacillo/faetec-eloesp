"""
    Esse código resgata os conteudos de file.txt que armazena os bits
    para cada coluna do display.

    Estrutura:

    01110
    10001
    10001
    11111
    10001
    10001
    10001

    Quando o bit é 1, aquele ponto no display estará aceso. Caso seja
    0, o ponto estará apagado.
"""

import os

FILE = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'file.txt')

#FILE = 'C:\\Users\\User\\OneDrive\\Área de Trabalho\\file.txt'

def read_file(path):
    chunks = []
    with open(path, 'r') as f:
        contents = f.read()
        chunks = contents.split('\n\n')

    for chunk in chunks:
        parts = chunk.split('\n')
        hexas = []
        
        for part in parts:
            hexas.append(hex(int(part, 2)))

        print('{', end=' ')
        print(*hexas, sep=', ', end='')
        print('},')
    
        
read_file(FILE)
