#
# Be sure to run `pod lib lint TencentMapSdk.podspec' to ensure this is a
# valid spec and remove all comments before submitting the spec.
#
# Any lines starting with a # are optional, but encouraged
#
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = "TencentMapSdk"
  s.version          = "2.1.1.04.01"
  s.summary          = "This is TencentMapSdk."
  s.description      = 'The Map Software develop kit.'
  s.homepage         = "https://github.com/TencentSDK/TencentMapSdk"
  # s.screenshots     = "www.example.com/screenshots_1", "www.example.com/screenshots_2"
  s.license          = 'BSD'
  s.author           = { "cleverzhang" => "cleverzhang@tencent.com" }
  s.source           = { :git => "https://github.com/TencentSDK/TencentMapSdk.git", :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.platform     = :ios, '8.0'
  s.requires_arc = true
  s.source_files = 'Pod/Classes/**/*'

  s.resources = 'Pod/Bundles/SOSOMAPRES.bundle'

  s.vendored_libraries = [
    'Pod/Library/libTencentMapSdk.a'
  ]

  s.frameworks = 'SystemConfiguration','UIKit','CoreText','OpenGLES','QuartzCore','CoreGraphics','CoreLocation','CoreTelephony'
  s.library = 'z','stdc++','sqlite3'


end
