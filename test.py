import cv2

# 读取图片
img = cv2.imread('/home/momo/Desktop/test/Screenshot_20230624_220006.png')

# 显示图片
cv2.imshow('Image', img)
cv2.waitKey(0)
