I=imread('my.jpg');%读入图像并进行灰度转换
imshow(I);
IGRAY=rgb2gray(I);
[m n]=size(IGRAY);
c=I(1,1);RLEcode(1,1:3)=[1 1 c];%建立数组RLEcode，其中元素排列形式为[行程起始行坐标、行程列坐标、灰度值]
t=2;
for k=1:m %进行行程编码
    for j=1:n
        if(not(and(k==1,j==1)))
            if(not(I(k,j)==c))
                 RLEcode(t,1:3)=[k j I(k,j)];
                 c=I(k,j);
                 t=t+1;
            end
        end
    end
end


