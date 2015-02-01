//-----------------------------------------------------------------------------
// #version:15# machine generated, do not edit!
//-----------------------------------------------------------------------------
#include "Pre.h"
#include "shaders.h"

namespace Oryol {
namespace Shaders {
const char* vs_100_src = 
"#define _POSITION gl_Position\n"
"uniform mat4 mvp;\n"
"attribute vec4 position;\n"
"attribute vec4 normal;\n"
"attribute vec2 texcoord0;\n"
"varying vec4 nrm;\n"
"varying vec2 uv;\n"
"void main() {\n"
"_POSITION = mvp * position;\n"
"nrm = normal;\n"
"uv = texcoord0;\n"
"}\n"
;
const char* fs_100_src = 
"precision mediump float;\n"
"#define _TEXTURE2D texture2D\n"
"#define _COLOR gl_FragColor\n"
"uniform sampler2D tex;\n"
"varying vec4 nrm;\n"
"varying vec2 uv;\n"
"void main() {\n"
"vec4 texColor = _TEXTURE2D(tex, uv * vec2(5.0, 3.0));\n"
"_COLOR = ((nrm * 0.5) + 0.5) * 0.75 + texColor * texColor * texColor * texColor;\n"
"}\n"
;
const char* vs_120_src = 
"#version 120\n"
"#define _POSITION gl_Position\n"
"uniform mat4 mvp;\n"
"attribute vec4 position;\n"
"attribute vec4 normal;\n"
"attribute vec2 texcoord0;\n"
"varying vec4 nrm;\n"
"varying vec2 uv;\n"
"void main() {\n"
"_POSITION = mvp * position;\n"
"nrm = normal;\n"
"uv = texcoord0;\n"
"}\n"
;
const char* fs_120_src = 
"#version 120\n"
"#define _TEXTURE2D texture2D\n"
"#define _COLOR gl_FragColor\n"
"uniform sampler2D tex;\n"
"varying vec4 nrm;\n"
"varying vec2 uv;\n"
"void main() {\n"
"vec4 texColor = _TEXTURE2D(tex, uv * vec2(5.0, 3.0));\n"
"_COLOR = ((nrm * 0.5) + 0.5) * 0.75 + texColor * texColor * texColor * texColor;\n"
"}\n"
;
const char* vs_150_src = 
"#version 150\n"
"#define _POSITION gl_Position\n"
"uniform mat4 mvp;\n"
"in vec4 position;\n"
"in vec4 normal;\n"
"in vec2 texcoord0;\n"
"out vec4 nrm;\n"
"out vec2 uv;\n"
"void main() {\n"
"_POSITION = mvp * position;\n"
"nrm = normal;\n"
"uv = texcoord0;\n"
"}\n"
;
const char* fs_150_src = 
"#version 150\n"
"#define _TEXTURE2D texture\n"
"#define _COLOR _FragColor\n"
"uniform sampler2D tex;\n"
"in vec4 nrm;\n"
"in vec2 uv;\n"
"out vec4 _FragColor;\n"
"void main() {\n"
"vec4 texColor = _TEXTURE2D(tex, uv * vec2(5.0, 3.0));\n"
"_COLOR = ((nrm * 0.5) + 0.5) * 0.75 + texColor * texColor * texColor * texColor;\n"
"}\n"
;
ProgramBundleSetup Main::CreateSetup() {
    ProgramBundleSetup setup("Main");
    setup.AddProgramFromSources(0, ShaderLang::GLSL100, vs_100_src, fs_100_src);
    setup.AddProgramFromSources(0, ShaderLang::GLSL120, vs_120_src, fs_120_src);
    setup.AddProgramFromSources(0, ShaderLang::GLSL150, vs_150_src, fs_150_src);
    setup.AddUniform("mvp", ModelViewProjection);
    setup.AddTextureUniform("tex", Texture);
    return setup;
}
}
}

