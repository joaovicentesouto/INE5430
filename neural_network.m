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

%codifica a entrada usando o esquema onehot, target i eh igual a 1 na linha i+1
TrainingOutput = onehot(input, target);

% onehot para testes
TestOutput = onehot(input_test, target);

% normalizacao entre -1 e 1
TrainingData = (((input*2)/255) -1)';
TestData = (((input_test*2)/255) -1)';

cont=1;

%cria rede neural
x=115
net = newff(TrainingData, TrainingOutput, x, {'tansig', 'tansig'}, 'traingdx');
net.trainParam.epochs=500;
net.trainParam.goal=0.01;

net.divideParam.trainRatio=0.85; % Tudo para treino
net.divideParam.valRatio=0.15;     % Nada para valid
net.divideParam.testRatio=0;    % Nada para teste

%Treine a rede.
net=train(net, TrainingData, TrainingOutput);

%Simule a rede para os dados do treinamento.
Y=sim(net, TrainingData);

%Sature a saida da rede para os mesmos valores de saida dos exemplos de treinamento.
YClass = sature(Y)

%Onehot yclass
a = onehot(YClass, YClass);

clear YClass;

%Simule  a rede para os dados de teste.
Y=sim(net, TestData);

%Sature a saida da rede para os mesmos valores de saida dos exemplos de treinamento.
YClass = sature(Y)

%Onehot yclass
b = onehot(YClass, YClass);