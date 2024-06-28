import shado
import numpy as np

def test_ppm_atm():
    n = int(10)
    r_sat = np.tile(np.array([-13205.655784525363,21522.519302073124,15446.72240793841]), (n,1))
    r_sun = np.tile(np.array([52727703.80386541,-126017147.89721917,-54630443.258015752]), (n,1))

    expected = np.tile(np.array([0.47483773]), (n,1))
    sf = shado.shadow_function(r_sat, r_sun)
    assert np.allclose(sf, expected)
