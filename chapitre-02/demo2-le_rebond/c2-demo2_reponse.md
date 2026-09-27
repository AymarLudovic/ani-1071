# Réponse

J'ai ajouté un rebond lorsque la hauteur `y` devient négative. La hauteur est alors remise à `0` et la vitesse est inversée puis multipliée par `-0.8`.

À chaque rebond, la balle repart donc avec une vitesse plus faible et atteint une hauteur maximale plus petite que lors du rebond précédent.

Avec `dt = 0.1`, les premières hauteurs maximales diminuent : environ `10 m`, puis `3.25 m`, `1.88 m`, `1.01 m` et `0.58 m`.

Cela montre que le coefficient `0.8` fait perdre de l'énergie à chaque rebond.

La balle finit donc par avoir des rebonds de plus en plus petits et le mouvement s'arrête lorsque la vitesse au rebond devient inférieure à `0.1 m/s`.
