clear all
close all

Data=csvread('fashion-mnist_train.csv',1,0);
input = Data(:,2:end);
target= Data(:,1);

Data=csvread('fashion-mnist_train.csv',1,0);
input_test = Data(:,2:end);
target_test= Data(:,1);

clearvars Data;

target_string={
0 'T-shirt/top';
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

%codifica a entrada usando o esquema onehot, target i eh igual a 1 na linha i+1
for i=1:size(input,1)
    class_index = target(i,1)+1;
    TrainingOutput(class_index, i) = 1;
end

% onehot para testes
for i=1:size(input_test,1)
    class_index = target_test(i,1)+1;
    TestOutput(class_index, i) = 1;
end

% normalizacao entre -1 e 1
TrainingData = (((input*2)/255) -1)';
TestData = (((input_test*2)/255) -1)';

%cria rede neural
x=80
net = newff(TrainingData, TrainingOutput, x, {'tansig', 'tansig'}, 'traingdx');
net.trainParam.epochs=500;
net.trainParam.goal=0.01;
%net.trainParam.lr=0.1;          %taxa de aprendizado
net.trainParam.max_fail=8;     %epocas com erro sobre validacao

net.divideParam.trainRatio=0.85; % Tudo para treino
net.divideParam.valRatio=0.15;     % Nada para valid
net.divideParam.testRatio=0;    % Nada para teste

%Treina a rede.
net=train(net, TrainingData, TrainingOutput);

%Simula a rede para os dados do treinamento.
Y=sim(net, TrainingData);

%Satura a saida da rede para os mesmos valores de saida dos exemplos de treinamento.
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

%Onehot yclass
for i=1:size(YClass,1)
    class_index = YClass(i,1)+1;
    TrainingResponse(class_index, i) = 1;
end

clear YClass;

%Simula a rede para os dados de teste.
Y=sim(net, TestData);

%Satura a saida da rede para os mesmos valores de saida dos exemplos de treinamento.
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

%Onehot yclass
for i=1:size(YClass,1)
    class_index = YClass(i,1)+1;
    TestResponse(class_index, i) = 1;
end