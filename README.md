Çarpılması istenen N adet matrisin çarpım sırasındaki yerleri değiştirilmeden,
hangi sıralarda çarpılmaları durumunda minimum harcamanın yapılacağı problemi olan 
Matrix-Chain Multiplication'ın dinamik programlama ile çözülmüş halidir.
Bir örnek ile açıklamak gerekirse eğer;

A matrisi 10×30, B matrisi 30×5, C matrisi 5×60 büyüklüğünde iken, AxBxC matris çarpımı yapılması istensin. 
Bu çarpmalar aşağıdaki parantezlemelerle gösterilen farklı öncelik sıraları ile yapılabilir : (AB)C = A(BC)
Çarpmaların hangi sıra ile yapıldığı sonucu değiştirmemesine rağmen yapılan işlem sayısı değişir.

ABC matris çarpımı işleminin aşağıda görülen iki farklı sıra ile yapılması için gerekli işlem sayıları farklıdır.

(AB)C = (10×30×5) + (10×5×60) = 1500 + 3000 = 4500 işlem

A(BC) = (30×5×60) + (10×30×60) = 9000 + 18000 = 27000 işlem
