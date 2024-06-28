"""
Example Example
===============
"""

import matplotlib.pyplot as plt
import numpy as np

x = np.linspace(0, np.pi, int(1e3))
y = np.sin(x)

plt.plot(x, y)
plt.show()
