RGB = imread('my.jpg');
I = rgb2gray(RGB);%ת��Ϊ�ĻҶ�ͼ��'
J = dct2(I);%�������ұ任
imshow(log(abs(J)),[]), colormap(jet(64)), colorbar%��ʾΪ64���Ҷȣ���ʾ��ɫ������ʾ�任���ϵ���ֲ�
J(abs(J) < 10) = 0; %��DCT�任���ϵ��ֵС��10��Ԫ����Ϊ0
K = idct2(J);%���з����ұ任
figure;
subplot (1,2,1);
imshow(I);title('ԭͼ��'); %��ʾԭͼ��
subplot(1,2,2);  
imshow(K,[0 255]);title('ѹ��ͼ��');%��ʾѹ�����ͼ�񡣶Ա�ԭʼͼ���ѹ�����ͼ����Ȼ������85%��DCTϵ������ͼ����Ȼ��������Ȼ��һЩ������ʧ��

