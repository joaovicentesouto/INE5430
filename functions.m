function output = onehot(input, targets)

    for i=1:size(input,1)
        class_index = targets(i,1)+1;
        output(class_index, i) = 1;
    end

end

function output = sature(input)

    for j=1:size(input,2)
        max = -1;
        index = -1;
        for i=1:size(input,1)
            if input(i,j) > max
                max = input(i,j);
                index = i;
            end
        end
        output(j,1) = index-1;
    end

end

% function y = onehot(input, target, output)

%     for i=1:size(input,1)
%         if target(i,1) == 0
%             output(1,i)=1;
%         elseif target(i,1) == 1
%             output(2,i)=1;
%         elseif target(i,1) == 2
%             output(3,i)=1;
%         elseif target(i,1) == 3
%             output(4,i)=1;
%         elseif target(i,1) == 4
%             output(5,i)=1;
%         elseif target(i,1) == 5
%             output(6,i)=1;
%         elseif target(i,1) == 6
%             output(7,i)=1;
%         elseif target(i,1) == 7
%             output(8,i)=1;
%         elseif target(i,1) == 8
%             output(9,i)=1;
%         else
%             output(10,i)=1;
%         end
%     end

% end