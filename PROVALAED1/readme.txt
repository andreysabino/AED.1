Sobre as funções:
Listar Só Nome (listarsonome):
Ela tem as variaveis do contato.
Ela abre a agenda num FILE chamado F.
O while (!feof) é um laço que se perdura enquanto for diferente do fim do arquivo.
Enquanto  arquivo tiver conteudo, ele lê a linha com as informações todas e imprime o ID e o nome.

Listar Nome e Telefone (listarnomeetelefone):
Ela é igual a anterior, a diferença é que ela lista o telefone também.

Listar por Inicial (listarporinicial):
Mesma estrutura, a diferença é a existencia de um IF.
Quando a primeira letra do nome for igual a letra que a função recebe como parametro, ele escreve a linha.
O toupper lê ambas as variaveis em caixa alta, para que o resultado de escrever a letra em minúsculo e maiusculo seja o mesmo:
a = A.

Listar por Indice (listarporindice):
Mesma estrutura da anterior, a diferença é que ela recebe um indice do usuário e usa o IF para comparar o indice digitado com os da agenda.
Aí ela imprime o que for igual.

Listar por profissão (listarporprofissao):
Exatamente igual a listar por inicial.
A diferença é que recebemos uma profissão do usuário e o IF compara com as profissões na agenda, se bater, imprime.

Exporta contato (exportacontato):
Ela cria um arquivo chamado de auxiliar.
Recebe as variaveis e abre a agenda.dat
A função percorre todo o arquivo, e quando achar o contato correspondente ao ID fornecido para o usuário ela imprime as informações de agenda.dat no auxiliar
Depois disso, a strcat pega o nome presente nas informações do ID específico e adiciona ".txt", para ficar nome.txt
Aí, o arquivo é renomeado com o nome do contato e o ".txt" no final.

formata:
Bom, ele usa o "w+" para limpar TODA a agenda, formatando ela.

Edita Nome e Edita Contato (editanome) (editacontato):
Elas usam um arquivo auxiliar e o agenda.dat
Elas recebem um ID, que define qual contato será alterado.
Enquanto elas n acham o ID, elas escrevem no auxiliar os outros contatos, quando acham, elas executam a condição de edição:
Depois, dentro da função, elas escaneiam o novo nome ou o novo contato dentro de sí (elas possuem uma variavel pra isso).
Então, no final, elas escrevem dentro do auxiliar as informações já alteradas.
Quando todo o processo de escrever no auxiliar ocorre, o agenda.dat é apagado e o programa torna o arquivo auxiliar o novo agenda.dat.

Comentários super grandes:

Linha 44:
Essa função "If" aqui dentro da função de exportar é devido a lista telefônica não estar em ordem crescente com todos os números apresentados, então toda vez que clico pra exportar um 
contato que não existe, como o contato 2, a função de exportar é executada criando um arquivo de nada, então a função serve para que todo número fora dos que estão na lista e possam ser 
clicados, não criem os arquivos, quando e diferente do intervalo que criamos como opções válidas, o arquivo é deletado pela função "remove" na mesma hora, impedindo que um arquivo de nada 
seja criado, economizando memória e impedindo o erro do arquivo vazio.

