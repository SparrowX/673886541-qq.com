I=imread('my.jpg');%����ͼ�񲢽��лҶ�ת��
imshow(I);
IGRAY=rgb2gray(I);
[m n]=size(IGRAY);
c=I(1,1);RLEcode(1,1:3)=[1 1 c];%��������RLEcode������Ԫ��������ʽΪ[�г���ʼ�����ꡢ�г������ꡢ�Ҷ�ֵ]
t=2;
for k=1:m %�����г̱���
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


