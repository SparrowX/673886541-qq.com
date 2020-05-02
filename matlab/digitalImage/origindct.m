RGB = imread('my.jpg');
I = rgb2gray(RGB);%转化为的灰度图像'
J = dct2(I);%进行余弦变换
imshow(log(abs(J)),[]), colormap(jet(64)), colorbar%显示为64级灰度，显示颜色条，显示变换后的系数分布
J(abs(J) < 10) = 0; %将DCT变换后的系数值小于10的元素设为0
K = idct2(J);%进行反余弦变换
figure;
subplot (1,2,1);
imshow(I);title('原图像'); %显示原图像
subplot(1,2,2);  
imshow(K,[0 255]);title('压缩图像');%显示压缩后的图像。对比原始图像和压缩后的图像，虽然舍弃了85%的DCT系数，但图像仍然清晰（当然有一些质量损失）

