#include "lab_m1/Tema2/Tema2.h"

#include <vector>
#include <string>
#include <iostream>
#include <random>

using namespace std;
using namespace m1;


std::random_device rd; 
std::mt19937 gen(rd());
std::uniform_real_distribution<float> dis(-10.0, 10.0);

/*
 *  To find out more about `FrameStart`, `Update`, `FrameEnd`
 *  and the order in which they are called, see `world.cpp`.
 */

glm::vec3 GenerateRandomPosition() {
    float x = dis(gen);
    float z = dis(gen);
    return glm::vec3(x, 0, z);
}
bool RandomDirection() {
    std::uniform_int_distribution<> dis(0, 1);
    return dis(gen) == 1;
}

Tema2::Tema2()
{
}


Tema2::~Tema2()
{
}


void Tema2::Init()
{

    float tankRotationAngle = 0.0f;

    {
        Mesh* mesh = new Mesh("TANK");
		mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "TANK.obj");
		meshes[mesh->GetMeshID()] = mesh;
    }

    {
        Mesh* mesh = new Mesh("sphere");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "sphere.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }

    {
        Mesh* mesh = new Mesh("sina1");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "sina1.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }
    
    {
		Mesh* mesh = new Mesh("sina2");
		mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "sina2.obj");
		meshes[mesh->GetMeshID()] = mesh;
	}

    {
        Mesh* mesh = new Mesh("corp");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "corp.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }

    {
        Mesh* mesh = new Mesh("turela");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "turela.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }

    {
        Mesh* mesh = new Mesh("tun");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "tun.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }

    {
        Mesh* mesh = new Mesh("c3");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "c3.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }

    {
        Mesh* mesh = new Mesh("c2");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "c2.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }

    {
        Mesh* mesh = new Mesh("c1");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "c1.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }

    {
        Mesh* mesh = new Mesh("sina1i");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "sina1.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }

    {
        Mesh* mesh = new Mesh("sina2i");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "sina2.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }

    {
        Mesh* mesh = new Mesh("corpi");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "corp.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }

    {
        Mesh* mesh = new Mesh("turelai");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "turela.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }

    {
        Mesh* mesh = new Mesh("tuni");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "tun.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }

    // Create a shader program for drawing face polygon with the color of the normal
    {
        Shader* shader = new Shader("LabShader");
        shader->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "Tema2", "shaders", "VertexShader.glsl"), GL_VERTEX_SHADER);
        shader->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "Tema2", "shaders", "FragmentShader.glsl"), GL_FRAGMENT_SHADER);
        shader->CreateAndLink();
        shaders[shader->GetName()] = shader;
    }


    {
        sina1pos = glm::vec3(0, 0, 0);
        materialShininess = 30;
        materialKd = 0.5;
        materialKs = 0.5;
    }
    {
        sina2pos = glm::vec3(0, 0, 0);
        materialShininess = 30;
        materialKd = 0.5;
        materialKs = 0.5;
    }
    {
        corppos = glm::vec3(0, 0, 0);
        materialShininess = 30;
        materialKd = 0.5;
        materialKs = 0.5;
    }
    {
        turelapos = glm::vec3(0,0, 0);
        materialShininess = 30;
        materialKd = 0.5;
        materialKs = 0.5;
    }
    {
        tunpos = glm::vec3(0, 0, 0);
        materialShininess = 30;
        materialKd = 0.5;
        materialKs = 0.5;
    }

    {
        c1pos = glm::vec3(10, 0, 10);
        materialShininess = 30;
        materialKd = 0.5;
        materialKs = 0.5;
    }
    {
		c2pos = glm::vec3(-20, 0, -10);
		materialShininess = 30;
		materialKd = 0.5;
		materialKs = 0.5;
	}
    {
		c3pos = glm::vec3(5, 0, -20);
		materialShininess = 30;
		materialKd = 0.5;
		materialKs = 0.5;
	}
    {
        c4pos = glm::vec3(-5, 0, 10);
        materialShininess = 30;
        materialKd = 0.5;
        materialKs = 0.5;
    }
    {
        c5pos = glm::vec3(5, 0, -3);
        materialShininess = 30;
        materialKd = 0.5;
        materialKs = 0.5;
    }
    {
        c6pos = glm::vec3(-3, 0, -8);
        materialShininess = 30;
        materialKd = 0.5;
        materialKs = 0.5;
    }

    Enemy enemy1;
    enemy1.position = glm::vec3(-10, 0, -5);
    enemy1.speed = 0.5f;
    enemy1.rotationAngle = 0.0f; 
    enemy1.changeDirectionInterval = 5.0f;
    enemy1.randomDestination = GenerateRandomPosition();
    enemy1.changeDestinationTime = 5.0f;
    enemies.push_back(enemy1);

    Enemy enemy2;
    enemy2.position = glm::vec3(10, 0, -7);
    enemy2.rotationAngle = 0.0f; 
    enemy2.changeDirectionInterval = 5.0f;
    enemy2.speed = 0.5f;
    enemy2.randomDestination = GenerateRandomPosition();
    enemy2.changeDestinationTime = 5.0f; 
    enemies.push_back(enemy2);

    Enemy enemy3;
    enemy3.position = glm::vec3(-10, 0, 10);
    enemy3.speed = 0.5f;
    enemy3.rotationAngle = 0.0f; 
    enemy3.changeDirectionInterval = 5.0f;
    enemy3.randomDestination = GenerateRandomPosition();
    enemy3.changeDestinationTime = 5.0f; 
    enemies.push_back(enemy3);

    gameTime = 0.0f;

}


void Tema2::FrameStart()
{
    // Clears the color buffer (using the previously set color) and depth buffer
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::ivec2 resolution = window->GetResolution();
    // Sets the screen area where to draw
    glViewport(0, 0, resolution.x, resolution.y);
}


void Tema2::Update(float deltaTimeSeconds)
{
    //cladiri
    {
        glm::mat4 modelMatrix = glm::mat4(1);
        modelMatrix = glm::translate(modelMatrix, c1pos);
        RenderSimpleMesh(meshes["c1"], shaders["LabShader"], modelMatrix, glm::vec3(0.5, 0.5, 0.5));
    }
    {
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix = glm::translate(modelMatrix, c2pos);
		RenderSimpleMesh(meshes["c2"], shaders["LabShader"], modelMatrix, glm::vec3(0.5, 0.5, 0.5));
	}
    {
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix = glm::translate(modelMatrix, c3pos);
		RenderSimpleMesh(meshes["c3"], shaders["LabShader"], modelMatrix, glm::vec3(0.5, 0.5, 0.5));
	}
    {
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix = glm::translate(modelMatrix, c4pos);
        modelMatrix = glm::scale(modelMatrix, glm::vec3(0.5f));
		RenderSimpleMesh(meshes["c1"], shaders["LabShader"], modelMatrix, glm::vec3(0.5, 0.5, 0.5));
	}
    {
        glm::mat4 modelMatrix = glm::mat4(1);
        modelMatrix = glm::translate(modelMatrix, c6pos);
        modelMatrix = glm::scale(modelMatrix, glm::vec3(0.5f));
        RenderSimpleMesh(meshes["c3"], shaders["LabShader"], modelMatrix, glm::vec3(0.5, 0.5, 0.5));
    }

    //tank
    {
		glm::mat4 modelMatrix = glm::mat4(1);
        modelMatrix = glm::translate(modelMatrix, sina1pos);
        modelMatrix = glm::rotate(modelMatrix, tankRotationAngle, glm::vec3(0, 1, 0)); // Rotație pe axa Y
        modelMatrix = glm::scale(modelMatrix, glm::vec3(0.25f));

		RenderSimpleMesh(meshes["sina1"], shaders["LabShader"], modelMatrix, glm::vec3(0.5, 0.5, 0.5));
	}

    {
        glm::mat4 modelMatrix = glm::mat4(1);
        modelMatrix = glm::translate(modelMatrix, sina2pos);
        modelMatrix = glm::rotate(modelMatrix, tankRotationAngle, glm::vec3(0, 1, 0)); // Rotație pe axa Y
        modelMatrix = glm::scale(modelMatrix, glm::vec3(0.25f));
        RenderSimpleMesh(meshes["sina2"], shaders["LabShader"], modelMatrix, glm::vec3(0.5, 0.5, 0.5));
    }

	{
		glm::mat4 modelMatrix = glm::mat4(1);
        modelMatrix = glm::translate(modelMatrix, corppos);
        modelMatrix = glm::rotate(modelMatrix, tankRotationAngle, glm::vec3(0, 1, 0)); // Rotație pe axa Y
        modelMatrix = glm::scale(modelMatrix, glm::vec3(0.25f));
		RenderSimpleMesh(meshes["corp"], shaders["LabShader"], modelMatrix, glm::vec3(0, 1, 0));
	}

	/* {
		glm::mat4 modelMatrix = glm::mat4(1);
       // modelMatrix = glm::rotate(modelMatrix, RADIANS(90.0f), glm::vec3(0, 1, 0));
        modelMatrix = glm::translate(modelMatrix, turelapos);
        modelMatrix = glm::rotate(modelMatrix, tankRotationAngle, glm::vec3(0, 1, 0)); // Rotație pe axa Y
        modelMatrix = glm::scale(modelMatrix, glm::vec3(0.25f));
		RenderSimpleMesh(meshes["turela"], shaders["LabShader"], modelMatrix, glm::vec3(0, 0.5, 0));
	}

	{
		glm::mat4 modelMatrix = glm::mat4(1);
        //modelMatrix = glm::rotate(modelMatrix, RADIANS(90.0f), glm::vec3(0, 1, 0));
        modelMatrix = glm::translate(modelMatrix, tunpos);
        modelMatrix = glm::rotate(modelMatrix, tankRotationAngle, glm::vec3(0, 1, 0)); // Rotație pe axa Y
        modelMatrix = glm::scale(modelMatrix, glm::vec3(0.25f));
		RenderSimpleMesh(meshes["tun"], shaders["LabShader"], modelMatrix, glm::vec3(0.5, 0.5, 0.5));
	}*/

    //turela care se misca
    glm::mat4 turretModelMatrix = glm::mat4(1);
    turretModelMatrix = glm::translate(turretModelMatrix, turelapos);
    turretModelMatrix = glm::rotate(turretModelMatrix, turretRotationAngle, glm::vec3(0, 1, 0)); // Rotație pe axa Y
    turretModelMatrix = glm::scale(turretModelMatrix, glm::vec3(0.25f));
    RenderSimpleMesh(meshes["turela"], shaders["LabShader"], turretModelMatrix, glm::vec3(0, 0.5, 0));

    glm::mat4 gunModelMatrix = glm::mat4(1);
    gunModelMatrix = glm::translate(gunModelMatrix, tunpos);
    gunModelMatrix = glm::rotate(gunModelMatrix, turretRotationAngle, glm::vec3(0, 1, 0)); // Rotație pe axa Y
    gunModelMatrix = glm::scale(gunModelMatrix, glm::vec3(0.25f));
    RenderSimpleMesh(meshes["tun"], shaders["LabShader"], gunModelMatrix, glm::vec3(0.5, 0.5, 0.5));

    for (auto& bullet : bullets) {
        bullet.position += bullet.direction * bullet.speed * deltaTimeSeconds;
        bullet.lifetime -= deltaTimeSeconds;
        glm::mat4 modelMatrix = glm::translate(glm::mat4(1.0f), bullet.position);
        modelMatrix = glm::scale(modelMatrix, glm::vec3(0.15f));
        RenderSimpleMesh(meshes["sphere"], shaders["LabShader"], modelMatrix, glm::vec3(0.2, 0.2, 0.2));
    }
    bullets.erase(std::remove_if(bullets.begin(), bullets.end(), 
        [](const Bullet& bullet) {
            return bullet.lifetime <= 0.0f;
        }), bullets.end());
    

    std::vector<Bullet> bulletsToKeep;
    for (auto& bullet : bullets) {
        bool collided = false;

        for (const auto& enemy : enemies) {
            if (glm::distance(bullet.position, enemy.position) < COLLISION_THRESHOLD) {
                collided = true;
                break;
            }
        }

        if (!collided) {
            for (const auto& buildingPosition : { c1pos, c2pos, c3pos, c4pos, c6pos }) {
                if (glm::distance(bullet.position, buildingPosition) < COLLISION_THRESHOLD) {
                    collided = true;
                    break;
                }
            }
        }

        if (!collided) {
            bulletsToKeep.push_back(bullet);
        }
    }

    bullets = bulletsToKeep;

    for (auto& enemy : enemies) {
        // Actualizare poziție spre destinația aleatoare
        glm::vec3 direction = glm::normalize(enemy.randomDestination - enemy.position);
        enemy.position += direction * enemy.speed * deltaTimeSeconds;

        // Actualizare timp și schimbare destinație dacă este necesar
        enemy.changeDestinationTime -= deltaTimeSeconds;
        if (enemy.changeDestinationTime <= 0) {
            enemy.randomDestination = GenerateRandomPosition();
            enemy.changeDestinationTime = 5.0f; // Resetare timp pentru noua destinație
        }
    }
    
    int i = 0;
    for (auto& enemy : enemies) {
        enemy.changeDirectionInterval -= deltaTimeSeconds;

        if (enemy.changeDirectionInterval <= 0) {
            // Alege un unghi aleatoriu de rotație la stânga sau la dreapta
            std::uniform_real_distribution<float> dis(-M_PI / 4, M_PI / 4); // De exemplu, între -45 și 45 de grade
            enemy.rotationAngle += dis(gen);

            enemy.changeDirectionInterval = 5.0f; // Resetează timer-ul
        }

        // Calculează direcția bazată pe unghiul de rotație
        glm::vec3 forward = glm::vec3(cos(enemy.rotationAngle), 0, sin(enemy.rotationAngle));
        forward = glm::normalize(forward);

        // Actualizează poziția
        enemy.position += forward * enemy.speed * deltaTimeSeconds;
        
        // Randarea inamicului
        glm::mat4 modelMatrix = glm::mat4(1);
        modelMatrix = glm::translate(modelMatrix, enemy.position);
        modelMatrix = glm::rotate(modelMatrix, enemy.rotationAngle, glm::vec3(0, 1, 0));
        modelMatrix = glm::scale(modelMatrix, glm::vec3(0.25f));
        if (i % 2 == 0) {
            modelMatrix = glm::rotate(modelMatrix, RADIANS(-90.0f), glm::vec3(0, 1, 0));
        }
        else {
            modelMatrix = glm::rotate(modelMatrix, RADIANS(90.0f), glm::vec3(0, 1, 0));
        }
        RenderSimpleMesh(meshes["sina1i"], shaders["LabShader"], modelMatrix, glm::vec3(0.5, 0.5, 0.5));
        RenderSimpleMesh(meshes["sina2i"], shaders["LabShader"], modelMatrix, glm::vec3(0.5, 0.5, 0.5));
        RenderSimpleMesh(meshes["corpi"], shaders["LabShader"], modelMatrix, glm::vec3(1, 0, 0));
        RenderSimpleMesh(meshes["turelai"], shaders["LabShader"], modelMatrix, glm::vec3(1, 0, 0));
        RenderSimpleMesh(meshes["tuni"], shaders["LabShader"], modelMatrix, glm::vec3(0.5, 0.5, 0.5));
        i++;
    }
    gameTime += deltaTimeSeconds;

    if (gameTime >= 60.0f) {
        window->Close(); 
    }

    if (timeSinceLastShot < 1.0f) {
        timeSinceLastShot += deltaTimeSeconds;
    }

}


void Tema2::FrameEnd()
{
    DrawCoordinateSystem();
}


void Tema2::RenderSimpleMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix, const glm::vec3& color)
{
    if (!mesh || !shader || !shader->GetProgramID())
        return;

    // Render an object using the specified shader and the specified position
    glUseProgram(shader->program);

    // Set shader uniforms for light & material properties
    // TODO(student): Set light position uniform
    //GLint loc_light_position = glGetUniformLocation(shader->program, "light_position");
   // glUniform3fv(loc_light_position, 1, glm::value_ptr(lightPosition));

    // TODO(student): Set eye position (camera position) uniform
    glm::vec3 eyePosition = GetSceneCamera()->m_transform->GetWorldPosition();
    GLint loc_eye_position = glGetUniformLocation(shader->program, "eye_position");
    glUniform3fv(loc_eye_position, 1, glm::value_ptr(eyePosition));

    // TODO(student): Set material property uniforms (shininess, kd, ks, object color)
    GLint loc = glGetUniformLocation(shader->program, "material_shininess");
    glUniform1i(loc, materialShininess);

    loc = glGetUniformLocation(shader->program, "material_kd");  // componenta difuza
    glUniform1f(loc, materialKd);

    loc = glGetUniformLocation(shader->program, "material_ks");  // componenta speculara
    glUniform1f(loc, materialKs);

    loc = glGetUniformLocation(shader->program, "object_color");
    glUniform3fv(loc, 1, glm::value_ptr(color));

    // Bind model matrix
    GLint loc_model_matrix = glGetUniformLocation(shader->program, "Model");
    glUniformMatrix4fv(loc_model_matrix, 1, GL_FALSE, glm::value_ptr(modelMatrix));

    // Bind view matrix
    glm::mat4 viewMatrix = GetSceneCamera()->GetViewMatrix();
    int loc_view_matrix = glGetUniformLocation(shader->program, "View");
    glUniformMatrix4fv(loc_view_matrix, 1, GL_FALSE, glm::value_ptr(viewMatrix));

    // Bind projection matrix
    glm::mat4 projectionMatrix = GetSceneCamera()->GetProjectionMatrix();
    int loc_projection_matrix = glGetUniformLocation(shader->program, "Projection");
    glUniformMatrix4fv(loc_projection_matrix, 1, GL_FALSE, glm::value_ptr(projectionMatrix));

    // Draw the object
    glBindVertexArray(mesh->GetBuffers()->m_VAO);
    glDrawElements(mesh->GetDrawMode(), static_cast<int>(mesh->indices.size()), GL_UNSIGNED_INT, 0);
}


/*
 *  These are callback functions. To find more about callbacks and
 *  how they behave, see `input_controller.h`.
 */


void Tema2::OnInputUpdate(float deltaTime, int mods)
{

    if (!window->MouseHold(GLFW_MOUSE_BUTTON_RIGHT))
    {
       

        float speed = 0.5f;
        glm::vec3 up = glm::vec3(0, 1, 0);
        glm::vec3 right = GetSceneCamera()->m_transform->GetLocalOXVector();
        glm::vec3 forward = GetSceneCamera()->m_transform->GetLocalOZVector();
        forward = glm::normalize(glm::vec3(forward.x, 0, forward.z));

        glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), tankRotationAngle, glm::vec3(0, 1, 0));
        glm::vec3 tankDirection = glm::vec3(rotationMatrix * glm::vec4(forward, 0.0));

        if (window->KeyHold(GLFW_KEY_A)) tankRotationAngle += deltaTime * speed;
        if (window->KeyHold(GLFW_KEY_W)) sina1pos -= tankDirection * deltaTime * speed;
        if (window->KeyHold(GLFW_KEY_D)) tankRotationAngle -= deltaTime * speed;
        if (window->KeyHold(GLFW_KEY_S)) sina1pos += tankDirection * deltaTime * speed;

        if (window->KeyHold(GLFW_KEY_A)) tankRotationAngle += deltaTime * speed;
        if (window->KeyHold(GLFW_KEY_W)) sina2pos -= tankDirection * deltaTime * speed;
        if (window->KeyHold(GLFW_KEY_D)) tankRotationAngle -= deltaTime * speed;
        if (window->KeyHold(GLFW_KEY_S)) sina2pos += tankDirection * deltaTime * speed;
        
        if (window->KeyHold(GLFW_KEY_A)) tankRotationAngle += deltaTime * speed;
        if (window->KeyHold(GLFW_KEY_W)) corppos -= tankDirection * deltaTime * speed;
        if (window->KeyHold(GLFW_KEY_D)) tankRotationAngle -= deltaTime * speed;
        if (window->KeyHold(GLFW_KEY_S)) corppos += tankDirection * deltaTime * speed;

        if (window->KeyHold(GLFW_KEY_A)) tankRotationAngle += deltaTime * speed;
        if (window->KeyHold(GLFW_KEY_W)) turelapos -= tankDirection * deltaTime * speed;
        if (window->KeyHold(GLFW_KEY_D)) tankRotationAngle -= deltaTime * speed;
        if (window->KeyHold(GLFW_KEY_S)) turelapos += tankDirection * deltaTime * speed;

        if (window->KeyHold(GLFW_KEY_A)) tankRotationAngle += deltaTime * speed;
        if (window->KeyHold(GLFW_KEY_W)) tunpos -= tankDirection * deltaTime * speed;
        if (window->KeyHold(GLFW_KEY_D)) tankRotationAngle -= deltaTime * speed;
        if (window->KeyHold(GLFW_KEY_S)) tunpos += tankDirection * deltaTime * speed;

    }
}



void Tema2::OnKeyPress(int key, int mods)
{
    // Add key press event
}


void Tema2::OnKeyRelease(int key, int mods)
{
    // Add key release event
}


void Tema2::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
    
    float sensibility = 0.005f;

    turretRotationAngle -= deltaX * sensibility;
    turretRotationAngle = fmod(turretRotationAngle, 2 * M_PI);
    if (turretRotationAngle < 0)
        turretRotationAngle -= 2 * M_PI;

}



void Tema2::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
   
    if (button == GLFW_MOUSE_BUTTON_RIGHT)
    {
        if (timeSinceLastShot >= 1.0f) {
        // Presupunem că avem o variabilă care reține offset-ul de la centrul turelei la vârful tunului
        glm::vec3 barrelEndOffset = glm::vec3(0, 0.5, -1.0f); // Acest offset ar trebui ajustat în funcție de dimensiunile turelei și tunului

        glm::mat4 turretModelMatrix = glm::mat4(1);
        turretModelMatrix = glm::translate(turretModelMatrix, turelapos); // presupunem că turelapos este poziția turelei
        turretModelMatrix = glm::rotate(turretModelMatrix, turretRotationAngle, glm::vec3(0, 1, 0));

        // Calculează poziția de spawn a glonțului
        glm::vec3 bulletSpawnPosition = glm::vec3(turretModelMatrix * glm::vec4(barrelEndOffset, 1.0f));

        // Direcția gloanțelor va fi în direcția în care turela este orientată
        glm::vec3 forward = glm::vec3(0, 0, -1); // Direcția inițială a tunului
        glm::vec3 bulletDirection = glm::vec3(turretModelMatrix * glm::vec4(forward, 0.0)); // Direcția tunului după rotație

        Bullet newBullet;
        newBullet.position = bulletSpawnPosition;
        newBullet.direction = glm::normalize(bulletDirection); // Normalizăm direcția
        newBullet.speed = 2.0f; // Viteza dorită
        newBullet.lifetime = 5.0f; // 5 secunde de viață

        bullets.push_back(newBullet);

        timeSinceLastShot = 0.0f;
		}
    }
    
}


void Tema2::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button release event
}


void Tema2::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}


void Tema2::OnWindowResize(int width, int height)
{
}
