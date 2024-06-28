import shado
import numpy as np
import time
import mirage.vis as mrv
import pyvista as pv
import mirage as mr


n = int(1e5)
r_sat = mr.spiral_sample_sphere(n) * 7000
r_sun = np.tile(np.array([52727703.80386541,-126017147.89721917,-54630443.258015752]), (n,1))

t1 = time.time()
sf = shado.shadow_function(r_sat, r_sun)
print(time.time()-t1)

pl = pv.Plotter()

mrv.scatter3(pl, r_sat, scalars=sf)
pl.show()

# print(sf)