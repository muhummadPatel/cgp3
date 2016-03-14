##Assignment 3: Marching Cubes and Free-Form Deformation

**Author** : Muhummad Yunus Patel  
**Student#** : PTLMUH006  
**Date** : 14-March-2016

**NOTE:** Should you require any clarification, please feel free to contact me
 at muhummad.patel@gmail.com. Thank you. :)

###Description:
This practical implements code to convert a VoxelVolume to a triangle mesh. This is done by implementing the MarchingCubes algorithm to extract an isosurface from the grid of voxel values in the VoxelVolume. The extracted triangle mesh is highly tesselated/coarse grained. To solve this issue, a laplacian smooth method was also implemented.

The laplacian smoothing operates on the extracted triangle mesh to smooth it until the user is satisfied with the result.

The smoothed triangle mesh can the be deformed using the implemented free-form deformation functionality. The user is presented with a lattice of control points that can be moved around the scene. Once the user is satisfied with the positioning of the control points, they can apply the deformation to the mesh. The triangle mesh will then be deformed appropriately. This allows users to generate more complex meshes than would otherwise be possible with constructive solid geometry(csg) methods alone.

The newly implemented functionality has been appropriately unit tested. The marching cubes, and laplacian smoothing functionality has been tested in the following files: test_mesh.h, and test_mesh.cpp. The free-form deformation functionality has been tested in the following files: test_ffd.h, and test_ffd.cpp.

###Compiling and Running the Solution:
* See instructions in InstallReadme.txt for instructions on setting up and compiling the project.
* To run the the Tesselate program:
    * First set up and build the project (see previous point).
    * Navigate to the build directory
    * Run ./tesselate/tessviewer
    * Tick the 'show scene' checkbox in the left panel
    * Tick the 'show lattice' checkbox in the left panel
    * Click the 'Voxelise' button in the left panel
    * Click the 'Extract Isosurface' button in the left panel
    * Click the 'Smooth' button in the left panel (as many times as required)
    * Choose a control point and move it using the sliders in the left panel
    * Click the 'Deform' button in the left panel to apply the deformation
    * You should now have a deformed mesh in the viewing area
* The unit tests will be automatically run when you build the project. (see InstallReadme.txt for instructions on setting up and building the project)
