DEBUG=JEKYLL_GITHUB_TOKEN=blank PAGES_API_URL=http://0.0.0.0

default:
	@gem install jekyll bundler && bundle install

update:
	@bundle update

clean:
	@bundle exec jekyll clean

clean-markdown:
	@find . -type f -name "*.md" -delete

clean-doxygen:
	@rm -rf _doxygen-headers
	@rm -rf _doxygen-source

clean-doxygen-built:
	@find code/ -type f -delete

clean-local: clean clean-doxygen

build: clean
	@${DEBUG} bundle exec jekyll build --profile --config _config.yml,.debug.yml

server: clean
	@${DEBUG} bundle exec jekyll server --livereload --config _config.yml,.debug.yml
