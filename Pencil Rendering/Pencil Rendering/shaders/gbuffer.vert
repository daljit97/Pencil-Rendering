varying vec3 normal, lightDirection, lightDir, eyeVec, halfVector;	//���ߣ����߷���
varying vec4 position;						//����λ�ã�֮�������2ά����
varying vec4 diffuse,ambientGlobal,ambient;	//��Դ��һЩ����
varying float dist;							//��Դ������ľ���,���ڼ���˥��
attribute vec3 curvatureDirection;			//�����ʷ���
attribute vec3 minCurvatureDirection;

void main()
{
	vec4 ecPos;
	vec3 aux;
	normal = normalize(gl_NormalMatrix * gl_Normal);
	ecPos = gl_ModelViewMatrix * gl_Vertex;						//����λ��
	aux = vec3(gl_LightSource[0].position-ecPos);
	lightDir = normalize(aux);
	dist = length(aux);
	halfVector = normalize(gl_LightSource[0].halfVector.xyz);

	//����diffuse,ambient��globalAmbient
	diffuse = gl_FrontMaterial.diffuse * gl_LightSource[0].diffuse;
	ambient = gl_FrontMaterial.ambient * gl_LightSource[0].ambient;
	ambientGlobal = gl_LightModel.ambient * gl_FrontMaterial.ambient;

	lightDirection = normalize(vec3(gl_LightSource[0].position));

	gl_Position = ftransform();
	position = gl_Position;
}