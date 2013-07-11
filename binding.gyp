{
	'targets': [
		{
			'target_name': 'kinecter',

			'conditions': [
				['target_arch=="x64"', { 'variables': { 'arch': 'amd64', 'kinect_lib': 'lib\<(arch)\Kinect10.lib' },
			}, { 'variables': { 'arch': 'x86', 'kinect_lib': 'lib\<(arch)\Kinect10.lib' },
            }]],

			'include_dirs': ['<!(echo %KINECTSDK10_DIR%)inc'],

			'libraries': ['-l <!(echo %KINECTSDK10_DIR%)<(kinect_lib)'],

			'sources': [
				'src\main.cpp',
				'src\Kinecter.cpp',
				'src\KinectSensor.cpp'
			]
		}
	]
}