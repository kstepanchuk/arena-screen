#include "CaptureTargets.h"
#include "Platform.h"

int FindTarget( const std::vector< CaptureTarget >& targets, const std::string& utf8Text )
{
	std::string needle = platform::LowercaseUtf8( utf8Text );
	if( needle.empty() )
		return -1;

	//Windows first: "chrome" should find the browser, not a monitor that happens to match.
	//Prefer displays when the query begins with a screen label; otherwise prefer app windows.
	bool monitorFirst = needle.compare( 0, 8, "pantalla" ) == 0 || needle.compare( 0, 10, "экран" ) == 0 || needle.compare( 0, 6, "screen" ) == 0;
	CaptureTarget::Kind first  = monitorFirst ? CaptureTarget::Kind::Monitor : CaptureTarget::Kind::Window;
	CaptureTarget::Kind second = monitorFirst ? CaptureTarget::Kind::Window : CaptureTarget::Kind::Monitor;
	for( CaptureTarget::Kind kind : { first, second } )
	{
		for( size_t index = 0; index < targets.size(); ++index )
		{
			if( targets[ index ].kind == kind && targets[ index ].searchKey.find( needle ) != std::string::npos )
				return static_cast< int >( index );
		}
	}
	return -1;
}
