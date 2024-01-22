#include <string>
#include <iostream>

#include "CGL/viewer.h"
#include "CGL/renderer.h"
#include "CGL/vector3D.h"
#include "CGL/matrix3x3.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define DEG2RAD 0.017453292519943295 // Conversion factor from degrees to radians

using namespace std;
using namespace CGL;
unsigned int texture;

/**
 * Part 2:
 * Write your own matrix vector multiplication function. Do not use the built-in CGL function!
 */
Vector3D mult(Matrix3x3 mat, Vector3D input) {
    /* TODO */
    Vector3D result;

    // Access columns of the matrix as vectors
    Vector3D col1 = Vector3D(mat(0, 0), mat(1, 0), mat(2, 0));
    Vector3D col2 = Vector3D(mat(0, 1), mat(1, 1), mat(2, 1));
    Vector3D col3 = Vector3D(mat(0, 2), mat(1, 2), mat(2, 2));

    // Perform the scalar-vector multiplications and sum them
    result = col1 * input.x + col2 * input.y + col3 * input.z;

    return result;
}

class QuadDrawer : public Renderer {
 public:

  QuadDrawer() : mat(1. / sqrt(2), 1. / sqrt(2), 0, -1. / sqrt(2), 1. / sqrt(2), 0, 0, 0, 1), a(-.75, .5, 0), b(-.75, -.5, 0.0), c(.75, -.5, 0.0), d(.75,0.5,0.0) { }

  ~QuadDrawer() { }

  string name() {
    return "Quad Drawing";
  }

  string info() {
    return "Quad Drawing";
  }

  void init() {
    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    // set the texture wrapping/filtering options (on the currently bound texture object)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    
    /*TODO: Change GL_NEAREST, and compare the effects of the following filters.
      The following are the following potential filter options:
      GL_LINEAR
      GL_NEAREST_MIPMAP_NEAREST
      GL_LINEAR_MIPMAP_NEAREST
      GL_NEAREST_MIPMAP_LINEAR
      GL_LINEAR_MIPMAP_LINEAR
     */
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    // load and generate the texture
    int width, height, nrChannels;
    //TODO: (optional) Change the picture here!
#ifdef _MSC_VER
    unsigned char* data = stbi_load("../../../wall.jpg", &width, &height, &nrChannels, 0);
#else
    unsigned char* data = stbi_load("../wall.jpg", &width, &height, &nrChannels, 0);
#endif
    if (data)
    {
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
    std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
    return;
  }
  
  //void render() {
  //    glBindTexture(GL_TEXTURE_2D, texture); // Comment this out to disable textures
  //    glBegin(GL_QUADS);

  //    glColor3f(1.0, 1.0, 0.0); // Can play with RGB values here :)
  //mult函数被用来对顶点进行矩阵变换。
  //    Vector3D a_trans = mult(mat, a);
  //    Vector3D b_trans = mult(mat, b);
  //    Vector3D c_trans = mult(mat, c);
  //    Vector3D d_trans = mult(mat, d);

  //    glTexCoord2f(0, 0);
  //    glVertex3f(a_trans[0], a_trans[1], a_trans[2]);
  //    /* TODO: change the (0,1) below to (0,.1) to zoom into the texture to see changes. */
  //    glTexCoord2f(0, 1);
  //    glVertex3f(b_trans[0], b_trans[1], b_trans[2]);
  //    /* TODO: change the (1,1) below to (.1,.1) to zoom into the texture to see changes. */
  //    glTexCoord2f(1, 1);
  //    glVertex3f(c_trans[0], c_trans[1], c_trans[2]);
  //    /* TODO: change the (1,0) to (.1,0) to zoom into the texture to see changes. */
  //    glTexCoord2f(1, 0);
  //    glVertex3f(d_trans[0], d_trans[1], d_trans[2]);
  //    glDeleteTextures(1, &texture);
  //    glDisable(GL_TEXTURE_2D);
  //    glEnd();
  //}

  void render() {
      // Sword butt
      glColor3f(0.3f, 0.2f, 0.1f); 
      glBegin(GL_QUADS);
      glVertex3f(-0.1f, -0.5f, 0.0f);
      glVertex3f(-0.1f, -0.6f, 0.0f);
      glVertex3f(0.1f, -0.6f, 0.0f);
      glVertex3f(0.1f, -0.5f, 0.0f);
      glEnd();


      // Draw the gem in the center of the sword butt
      float gemCenterX = 0.0f; // Center X coordinate
      float gemCenterY = -0.55f; // Center Y coordinate
      float gemRadius = 0.04f; 
      glBegin(GL_POLYGON);
      for (int i = 0; i < 360; i += 5) {
          float degInRad = i * DEG2RAD;
          glColor3f(0.4f * (cos(degInRad) + 1), 0.0f, 0.0f); // Darker red towards the edges
          glVertex3f(cos(degInRad) * gemRadius + gemCenterX, sin(degInRad) * gemRadius + gemCenterY, 0.0f);
      }
      glEnd();

      //// Add a larger specular highlight to the gem
      //glBegin(GL_POINTS);
      //glPointSize(100.00f); // Increase the point size for a larger highlight
      //glColor3f(1.0f, 1.0f, 1.0f); // White for the highlight
      //glVertex3f(gemCenterX, gemCenterY + gemRadius * 0.6f, 0.0f); // Offset from the center for highlight
      //glEnd();
      // Add a larger specular highlight to the gem with a small quad
      float highlightSize = 0.005f; // Set the size of the highlight quad
      float highlightOffsetX = gemCenterX; // X offset for the highlight
      float highlightOffsetY = gemCenterY + gemRadius * 0.6f; // Y offset for the highlight
      glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f); // White for the highlight
      glVertex3f(highlightOffsetX - highlightSize, highlightOffsetY - highlightSize, 0.0f);
      glVertex3f(highlightOffsetX - highlightSize, highlightOffsetY + highlightSize, 0.0f);
      glVertex3f(highlightOffsetX + highlightSize, highlightOffsetY + highlightSize, 0.0f);
      glVertex3f(highlightOffsetX + highlightSize, highlightOffsetY - highlightSize, 0.0f);
      glEnd();


      // Draw the sword handle with different shades of brown
      glBegin(GL_QUADS);
      glColor3f(0.35f, 0.16f, 0.14f); // Darker brown on the left
      glVertex3f(-0.06f, -0.6f, 0.0f);
      glVertex3f(-0.06f, -0.9f, 0.0f);
      glColor3f(0.55f, 0.27f, 0.07f); // Lighter brown on the right
      glVertex3f(0.06f, -0.9f, 0.0f);
      glVertex3f(0.06f, -0.6f, 0.0f);
      glEnd();

      // Draw the sword blade with a gradient from dark gray to light gray
      glBegin(GL_QUADS);
      glColor3f(0.3f, 0.3f, 0.3f); // Dark gray on the left side
      glVertex3f(-0.05f, -0.5f, 0.0f);
      glVertex3f(-0.05f, 0.5f, 0.0f);
      glColor3f(0.8f, 0.8f, 0.8f); // Light gray on the right side
      glVertex3f(0.05f, 0.5f, 0.0f);
      glVertex3f(0.05f, -0.5f, 0.0f);
      glEnd();

      // Draw the sword tip with a gradient from dark gray to light gray
      glBegin(GL_TRIANGLES);
      glColor3f(0.3f, 0.3f, 0.3f); // Dark gray on the left side of the tip
      glVertex3f(-0.05f, 0.5f, 0.0f);
      glColor3f(0.8f, 0.8f, 0.8f); // Light gray on the right side of the tip
      glVertex3f(0.05f, 0.5f, 0.0f);
      glColor3f(0.55f, 0.55f, 0.55f); // Intermediate gray for the tip top
      glVertex3f(0.0f, 0.7f, 0.0f);
      glEnd();
  }
  void resize(size_t w, size_t h) {
    
    this->w = w;
    this->h = h;

    return;
  }
  
 private:
  // frame buffer size
  size_t w, h; 
  Matrix3x3 mat;
  Vector3D a;
  Vector3D b;
  Vector3D c;
  Vector3D d;

};

int main( int argc, char** argv ) {

  // create viewer
  Viewer viewer = Viewer();

  // defined a user space renderer
  Renderer* renderer = new QuadDrawer();

  // set user space renderer
  viewer.set_renderer(renderer);

  // start the viewer
  viewer.init(600, 600);
  viewer.start();

  return 0;
}

