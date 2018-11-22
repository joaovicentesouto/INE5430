clear all
close all

Data=importfile('fashion-mnist_train.csv',2,inf);
input = Data(:,2:end);
target= Data(:,1);

Data=importfile('fashion-mnist_test.csv',2,inf);
input_test = Data(:,2:end);
target_test= Data(:,1);

clearvars Data;

target_string={0 'T-shirt/top';
1 'Trouser';
2 'Pullover';
3 'Dress';
4 'Coat';
5 'Sandal';
6 'Shirt';
7 'Sneaker';
8 'Bag';
9 'Ankle boot'};

figure;
colormap(gray);

perm = randperm(60000,20);
for i = 1:20
    subplot(4,5,i);
    display_array=reshape(input(perm(i),:),[28 28]);
    imshow(display_array',[]);
    xlabel(target_string{target(perm(i))+1,2});
end

% A partir deste ponto os dados já estão importados para o ambiente.
% Entretanto você tem de atentar que:
%     - as entradas e saídas para uma rede neural no MATLAB estão nas linhas
% da matriz;
%     - se o problema é de classificação é desejável codificar as
% saídas categóricas usando o esquema "onehot" onde cada neurônio da camada
% de saída codifica uma dada categoria.

%codifica a entrada usando o esquema onehot, target i eh igual a 1 na linha
%i+1
for i=1:size(input,1)
    if target(i,1) == 0
        SaidaTrein(1,i)=1;
    elseif target(i,1) == 1
        SaidaTrein(2,i)=1;
    elseif target(i,1) == 2
        SaidaTrein(3,i)=1;
    elseif target(i,1) == 3
        SaidaTrein(4,i)=1;
    elseif target(i,1) == 4
        SaidaTrein(5,i)=1;
    elseif target(i,1) == 5
        SaidaTrein(6,i)=1;
    elseif target(i,1) == 6
        SaidaTrein(7,i)=1;
    elseif target(i,1) == 7
        SaidaTrein(8,i)=1;
    elseif target(i,1) == 8
        SaidaTrein(9,i)=1;
    else
        SaidaTrein(10,i)=1;
    end
end
% onehot para testes
for i=1:size(input_test,1)
    if target_test(i,1) == 0
        SaidaTest(1,i)=1;
    elseif target_test(i,1) == 1
        SaidaTest(2,i)=1;
    elseif target_test(i,1) == 2
        SaidaTest(3,i)=1;
    elseif target_test(i,1) == 3
        SaidaTest(4,i)=1;
    elseif target_test(i,1) == 4
        SaidaTest(5,i)=1;
    elseif target_test(i,1) == 5
        SaidaTest(6,i)=1;
    elseif target_test(i,1) == 6
        SaidaTest(7,i)=1;
    elseif target_test(i,1) == 7
        SaidaTest(8,i)=1;
    elseif target_test(i,1) == 8
        SaidaTest(9,i)=1;
    else
        SaidaTest(10,i)=1;
    end
end
% normalizacao entre -1 e 1
TreinDados = (((input*2)/255) -1)';
TestDados = (((input_test*2)/255) -1)';
cont=1;
%cria rede neural
x=115
net = newff(TreinDados,SaidaTrein,x,{'tansig', 'tansig'},'traingdx');
net.trainParam.epochs=500;
net.trainParam.goal=0.01;

net.divideParam.trainRatio=0.85; % Tudo para treino
net.divideParam.valRatio=0.15;     % Nada para valid
net.divideParam.testRatio=0;    % Nada para teste

%Treine a rede.
net=train(net,TreinDados,SaidaTrein);

%Simule a rede para os dados do treinamento.
Y=sim(net,TreinDados);

%Sature a saida da rede para os mesmos valores de saida dos exemplos de treinamento.
for j=1:size(Y,2)
    max = -1;
    index = -1;
    for i=1:size(Y,1)
        if Y(i,j) > max
            max = Y(i,j);
            index = i;
        end
    end
    YClass(j,1) = index-1;
end

for i=1:size(YClass,1)
    if YClass(i,1) == 0
        a(1,i)=1;
    elseif YClass(i,1) == 1
        a(2,i)=1;
    elseif YClass(i,1) == 2
        a(3,i)=1;
    elseif YClass(i,1) == 3
        a(4,i)=1;
    elseif YClass(i,1) == 4
        a(5,i)=1;
    elseif YClass(i,1) == 5
        a(6,i)=1;
    elseif YClass(i,1) == 6
        a(7,i)=1;
    elseif YClass(i,1) == 7
        a(8,i)=1;
    elseif YClass(i,1) == 8
        a(9,i)=1;
    else
        a(10,i)=1;
    end
end

clear YClass;
%Simule  a rede para os dados de teste.
Y=sim(net,TestDados);

%Sature a saida da rede para os mesmos valores de saida dos exemplos de treinamento.
for j=1:size(Y,2)
    max = -1;
    index = -1;
    for i=1:size(Y,1)
        if Y(i,j) > max
            max = Y(i,j);
            index = i;
        end
    end
    YClass(j,1) = index-1;
end

for i=1:size(YClass,1)
    if YClass(i,1) == 0
        b(1,i)=1;
    elseif YClass(i,1) == 1
        b(2,i)=1;
    elseif YClass(i,1) == 2
        b(3,i)=1;
    elseif YClass(i,1) == 3
        b(4,i)=1;
    elseif YClass(i,1) == 4
        b(5,i)=1;
    elseif YClass(i,1) == 5
        b(6,i)=1;
    elseif YClass(i,1) == 6
        b(7,i)=1;
    elseif YClass(i,1) == 7
        b(8,i)=1;
    elseif YClass(i,1) == 8
        b(9,i)=1;
    else
        b(10,i)=1;
    end
end