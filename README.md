# ⚡ Projeto semestral  - Linguagem de programação
Projeto para praticar malloc, alloc, realloc, estruturas, headers e escrita em arquivos utilizando a linguagem de programação C.
<br>
<img src="https://upload.wikimedia.org/wikipedia/commons/3/35/The_C_Programming_Language_logo.svg" width="100" alt="Logotipo da linguagem C"/>

## 🪒 Resumo dos tópicos
- Contexto
- Planejamento
- Ferramentas
- Organização do projeto
- Conclusão

## 📕 Contexto
A ideia do projeto é criar um gerenciar de banco, tendo as seguintes funções:
- Inserir
- Alterar
- Listar
- Saldo Geral
- Procurar
- Depositar
- Sacar
- Imprimir
- Menu
- Arquivo morto
**A alocação dinâmica de memória é obrigatória!**

## 💭 Planejamento
Todo o planejamento do projeto foi realizado através da ferramenta Trello. Utilizamos o Kanban para organização, quebrando o projeto em pequenas tarefas, onde cada membro do time pegava para si a tarefa que sentisse vontade.

<img src="https://raw.githubusercontent.com/manzolimatheus/projeto-lpl/main/public/img/Trello.jpg" alt="Kanban do Trello"/>

## 🔧 Ferramentas

Para trabalhar de forma unida e compartilhada, utilizamos da ferramenta Replit, um editor de código que suporta diversas linguagens, incluindo a C.

<img src="https://replit.com/public/images/ogBanner.png" alt="Replit"/>

## 💼 Organização do projeto

### 🏯 Arquitetura
A estrutura de arquivos que utilizamos foi a MVC (Movel-View-Controller), adaptamos seu uso para a linguagem C, onde a Controller contém os recursos e processamento, a model a estrutura do objeto e a view onde é requisitado os dados para o usuário.

### 🤖 Testes automatizados
Para garantir o funcionamento adequado da aplicação, utilizamos de testes automatizados através de funções de asserção personalizadas, criadas pelo time.

<img src="https://raw.githubusercontent.com/manzolimatheus/projeto-lpl/main/public/img/Testes.jpg">

### 🆘 Helpers
Dentro do projeto existem também helpers, contendo funções auxiliares para o projeto, como funções para exibir uma linha na tela.

### 🎲 Banco de dados
Criamos uma forma primitiva de banco de dados, onde salvamos as contas em um arquivo .csv, existe um controlador personalizado de fácil uso para executar transações para o banco. O uso do .csv é essencial, já que a partir disso o usuário pode consumir os dados no Excel. Também podemos citar a integração com a nuvem feita com Python, que goza do uso do .csv.

### 📁 Estrutura de pastas
Abaixo, pode-se observar a estrutura do projeto.

<img src="https://github.com/manzolimatheus/projeto-lpl/blob/main/public/img/Pastas.jpg?raw=true" alt="Estrutura de pastas" />

### ☁️ Nuvem
Como Cloud, utilizamos uma API open-source chamada Strapi, onde apenas são modeladas as "tabelas" do projeto, de forma que todas as requisições - sejam elas POST, GET, PUT ou DELETE - já ficam com suas rotas prontas para uso, facilitando assim o desenvolvimento. Além disso, para que essas requisições fossem feitas, utilizamos um script em Python que lê os dados do arquivo .csv e os envia para dentro da API que salva esses dados no banco.
Por fim, como local de hospedagem dessa API, utilizamos nossa própria VPS na Oracle Cloud.

<img src="https://raw.githubusercontent.com/manzolimatheus/projeto-lpl/main/public/img/strapi logo.png" alt="Logo do Strapi">


## 🌱 Conclusão
Com o desenvolvimento do projeto, aplicamos testes automatizados, alocação dinâmica, estruturas, tipos personalizados, boas práticas de programação, arquiteturas e integrações. Através desses conhecimentos, pudemos nos aprofundar no "mundo do código" e entender como as linguagens de alto nível funcionam por baixo dos panos.
