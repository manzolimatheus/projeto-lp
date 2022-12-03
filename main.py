import os
import csv
import sys

try:
  import requests
except:
  try:
    os.system("pip install requests --user")
    import requests
  except:
    print("Erro ao instalar bibliotecas.")

type_func = sys.argv[1]
url = "http://150.230.67.252:1337/api/contas"
path = "./database/accounts.csv"
headers = {'Content-Type': 'application/json'}

if type_func == "get":
    def getCSV():
      try:
        r = requests.get(url, allow_redirects=True, timeout=5)
        body = r.json()
        f = open(path, 'w', newline='', encoding='utf-8')
        gravar = csv.writer(f)
        gravar.writerow(["id","name","isSpecial","balance","isDeleted"])
        for i in body['data']:
            gravar.writerow([i['id'],i['attributes']['name'],1 if i['attributes']['isSpecial'] == True else 0,i['attributes']['balance'],1 if i['attributes']['isDeleted'] else 0])
      except:
        print("Erro ao se conectar com a nuvem. Tente novamente mais tarde.")
    getCSV()

if type_func == "post":
    dic = {}
    id = sys.argv[2]
    
    with open(path, encoding='utf-8') as path:
        tabela = csv.reader(path, delimiter=',')
        line_count = 0
        for row in tabela:
            if line_count == 0:
                line_count += 1
            else:
                line_count += 1
                if row[0] == id:
                    dic['data'] = {"name": row[1], "isSpecial": int(row[2]), "balance": float(row[3]), "isDeleted": int(row[4])}
                    id = row[0]
                    break

    try:
      r = requests.post(url, json=dic, headers=headers, timeout=5)
      if r.status_code == 200:
          print("Dados sincronizados com sucesso.")
          print("+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-")
          print(f"| Conta número: {id}")
          print(f"| Olá, {dic['data']['name']}. Seu saldo eh de: R${dic['data']['balance']} . Conta especial: {'sim' if dic['data']['isSpecial'] == 1 else 'nao'}.")
          print("+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-")
    except:
      print("Erro ao se conectar com a nuvem. Tente novamente mais tarde.")

if type_func == "put":

    dic = {}
    id = sys.argv[2]

    with open(path, encoding='utf-8') as path:
        tabela = csv.reader(path, delimiter=',')
        line_count = 0
        for row in tabela:
            if line_count == 0:
                line_count += 1
            else:
                line_count += 1
                if row[0] == id:
                    dic['data'] = {"name": row[1], "isSpecial": int(row[2]), "balance": float(row[3]), "isDeleted": int(row[4])}
                    id = row[0]
                    break


    try:
      r = requests.put(url+f"/{id}", json=dic, headers=headers, timeout=5)
      if r.status_code == 200:
          print("Dados sincronizados com sucesso.")
          print("+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-")
          print(f"| Conta número: {id}")
          print(f"| Olá, {dic['data']['name']}. Seu saldo agora eh de: R${dic['data']['balance']}")
          print("+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-")
    except:
      print("Erro ao se conectar com a nuvem. Tente novamente mais tarde.")