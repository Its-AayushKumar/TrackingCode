const { useState, useEffect, useRef } = React;
const { createRoot } = ReactDOM;

// Register GSAP ScrollTrigger
gsap.registerPlugin(ScrollTrigger);

// ==========================================
// 1. HELPER COMPONENTS & SVGs
// ==========================================

const LucideIcon = ({ name, className = "w-5 h-5", strokeWidth = 2 }) => {
  // Safe inline SVG icons to prevent CDN import resolution issues
  const icons = {
    compass: (
      <svg className={className} fill="none" viewBox="0 0 24 24" stroke="currentColor" strokeWidth={strokeWidth}>
        <circle cx="12" cy="12" r="10" />
        <polygon points="16.24 7.76 14.12 14.12 7.76 16.24 9.88 9.88 16.24 7.76" />
      </svg>
    ),
    layers: (
      <svg className={className} fill="none" viewBox="0 0 24 24" stroke="currentColor" strokeWidth={strokeWidth}>
        <polygon points="12 2 2 7 12 12 22 7 12 2" />
        <polyline points="2 17 12 22 22 17" />
        <polyline points="2 12 12 17 22 12" />
      </svg>
    ),
    zap: (
      <svg className={className} fill="none" viewBox="0 0 24 24" stroke="currentColor" strokeWidth={strokeWidth}>
        <polygon points="13 2 3 14 12 14 11 22 21 10 12 10 13 2" />
      </svg>
    ),
    arrowRight: (
      <svg className={className} fill="none" viewBox="0 0 24 24" stroke="currentColor" strokeWidth={strokeWidth}>
        <line x1="5" y1="12" x2="19" y2="12" />
        <polyline points="12 5 19 12 12 19" />
      </svg>
    ),
    check: (
      <svg className={className} fill="none" viewBox="0 0 24 24" stroke="currentColor" strokeWidth={strokeWidth}>
        <polyline points="20 6 9 17 4 12" />
      </svg>
    ),
    globe: (
      <svg className={className} fill="none" viewBox="0 0 24 24" stroke="currentColor" strokeWidth={strokeWidth}>
        <circle cx="12" cy="12" r="10" />
        <line x1="2" y1="12" x2="22" y2="12" />
        <path d="M12 2a15.3 15.3 0 0 1 4 10 15.3 15.3 0 0 1-4 10 15.3 15.3 0 0 1-4-10 15.3 15.3 0 0 1 4-10z" />
      </svg>
    ),
    shield: (
      <svg className={className} fill="none" viewBox="0 0 24 24" stroke="currentColor" strokeWidth={strokeWidth}>
        <path d="M12 22s8-4 8-10V5l-8-3-8 3v7c0 6 8 10 8 10z" />
      </svg>
    ),
    github: (
      <svg className={className} fill="none" viewBox="0 0 24 24" stroke="currentColor" strokeWidth={strokeWidth}>
        <path d="M9 19c-5 1.5-5-2.5-7-3m14 6v-3.87a3.37 3.37 0 0 0-.94-2.61c3.14-.35 6.44-1.54 6.44-7A5.44 5.44 0 0 0 20 4.77 5.07 5.07 0 0 0 19.91 1S18.73.65 16 2.48a13.38 13.38 0 0 0-7 0C6.27.65 5.09 1 5.09 1A5.07 5.07 0 0 0 5 4.77a5.44 5.44 0 0 0-1.5 3.78c0 5.42 3.3 6.61 6.44 7A3.37 3.37 0 0 0 9 18.13V22" />
      </svg>
    ),
    linkedin: (
      <svg className={className} fill="none" viewBox="0 0 24 24" stroke="currentColor" strokeWidth={strokeWidth}>
        <path d="M16 8a6 6 0 0 1 6 6v7h-4v-7a2 2 0 0 0-2-2 2 2 0 0 0-2 2v7h-4v-7a6 6 0 0 1 6-6z" />
        <rect x="2" y="9" width="4" height="12" />
        <circle cx="4" cy="4" r="2" />
      </svg>
    ),
    mail: (
      <svg className={className} fill="none" viewBox="0 0 24 24" stroke="currentColor" strokeWidth={strokeWidth}>
        <path d="M4 4h16c1.1 0 2 .9 2 2v12c0 1.1-.9 2-2 2H4c-1.1 0-2-.9-2-2V6c0-1.1.9-2 2-2z" />
        <polyline points="22,6 12,13 2,6" />
      </svg>
    ),
    phone: (
      <svg className={className} fill="none" viewBox="0 0 24 24" stroke="currentColor" strokeWidth={strokeWidth}>
        <path d="M22 16.92v3a2 2 0 0 1-2.18 2 19.79 19.79 0 0 1-8.63-3.07 19.5 19.5 0 0 1-6-6 19.79 19.79 0 0 1-3.07-8.67A2 2 0 0 1 4.11 2h3a2 2 0 0 1 2 1.72 12.84 12.84 0 0 0 .7 2.81 2 2 0 0 1-.45 2.11L8.09 9.91a16 16 0 0 0 6 6l1.27-1.27a2 2 0 0 1 2.11-.45 12.84 12.84 0 0 0 2.81.7A2 2 0 0 1 22 16.92z" />
      </svg>
    ),
    fileText: (
      <svg className={className} fill="none" viewBox="0 0 24 24" stroke="currentColor" strokeWidth={strokeWidth}>
        <path d="M14 2H6a2 2 0 0 0-2 2v16a2 2 0 0 0 2 2h12a2 2 0 0 0 2-2V8z" />
        <polyline points="14 2 14 8 20 8" />
        <line x1="16" y1="13" x2="8" y2="13" />
        <line x1="16" y1="17" x2="8" y2="17" />
        <polyline points="10 9 9 9 8 9" />
      </svg>
    )
  };
  return icons[name] || null;
};

// ==========================================
// 2. MAIN APP COMPONENT
// ==========================================

function App() {
  const [isScrolled, setIsScrolled] = useState(false);
  const [isMenuOpen, setIsMenuOpen] = useState(false);
  const [activeMilestone, setActiveMilestone] = useState(0);

  // Monitor scroll height for floating pill navbar glass transformation
  useEffect(() => {
    const handleScroll = () => {
      setIsScrolled(window.scrollY > 80);
    };
    window.addEventListener('scroll', handleScroll);
    return () => window.removeEventListener('scroll', handleScroll);
  }, []);

  // Global GSAP Context for memory cleanup
  const appRef = useRef(null);

  useEffect(() => {
    const ctx = gsap.context(() => {
      // Hero opening intro animations (staggered fade-up)
      gsap.fromTo('.hero-fade-up',
        { opacity: 0, y: 40 },
        { opacity: 1, y: 0, duration: 1.2, stagger: 0.1, ease: 'power3.out', delay: 0.2 }
      );

      // Split Text Reveal on Scroll Trigger for About Section Heading
      const aboutWords = document.querySelectorAll('.about-word');
      gsap.fromTo(aboutWords,
        { opacity: 0.1, y: 10 },
        {
          scrollTrigger: {
            trigger: '.about-text-container',
            start: 'top 85%',
            end: 'bottom 60%',
            scrub: true,
          },
          opacity: 1,
          y: 0,
          stagger: 0.05,
          ease: 'power1.out'
        }
      );

      // Staggered Skills Cards reveal
      gsap.fromTo('.skill-card',
        { opacity: 0, y: 40 },
        {
          scrollTrigger: {
            trigger: '.skills-grid',
            start: 'top 80%',
          },
          opacity: 1,
          y: 0,
          duration: 0.8,
          stagger: 0.15,
          ease: 'power2.out'
        }
      );

      // Staggered Projects reveal
      gsap.fromTo('.project-card-anim',
        { opacity: 0, y: 50 },
        {
          scrollTrigger: {
            trigger: '.projects-section',
            start: 'top 75%',
          },
          opacity: 1,
          y: 0,
          duration: 1,
          stagger: 0.2,
          ease: 'power3.out'
        }
      );

      // Staggered Current Focus Cards reveal
      gsap.fromTo('.focus-card',
        { opacity: 0, y: 45 },
        {
          scrollTrigger: {
            trigger: '.focus-grid',
            start: 'top 80%',
          },
          opacity: 1,
          y: 0,
          duration: 0.8,
          stagger: 0.15,
          ease: 'power3.out'
        }
      );

    }, appRef);

    return () => ctx.revert();
  }, []);

  // Setup vertical timeline scroll tracking
  useEffect(() => {
    const timelineItems = document.querySelectorAll('.timeline-item-trigger');
    const triggers = [];

    timelineItems.forEach((item, index) => {
      const trigger = ScrollTrigger.create({
        trigger: item,
        start: 'top 65%',
        end: 'bottom 35%',
        onToggle: (self) => {
          if (self.isActive) {
            setActiveMilestone(index);
          }
        }
      });
      triggers.push(trigger);
    });

    return () => {
      triggers.forEach(t => t.kill());
    };
  }, []);

  const milestones = [
    { id: 'c', year: 'Phase 01', title: 'Started learning C', desc: 'Discovered the world of binary compilation, structured instructions, memory addressing, and basic execution flows.' },
    { id: 'quiz', year: 'Phase 02', title: 'Built Quiz Application', desc: 'Crafted an interactive console questionnaire system in C. Practiced arrays, memory buffers, and programmatic state loops.' },
    { id: 'comp1', year: 'Phase 03', title: 'College Coding Competitions', desc: 'Tested speed, layout parsing, and procedural logic under time constraints in local competitive hacking challenges.' },
    { id: 'cpp', year: 'Phase 04', title: 'Learned C++', desc: 'Dived deep into standard Object-Oriented paradigms, custom templates, classes, pointer arrays, and complexity analysis.' },
    { id: 'library', year: 'Phase 05', title: 'Built Library Management System', desc: 'Engineered a file-based catalog system in C++. Handled manual object serialization, storage files, and persistent state structures.' },
    { id: 'comp2', year: 'Phase 06', title: 'Advanced Coding Competition', desc: 'Refined problem-solving capabilities by tackling complex graph and tree queries under restrictive execution times.' },
    { id: 'python', year: 'Phase 07', title: 'Learned Python', desc: 'Embraced fast scripting, clean syntax formatting, standard library modules, and modular codebase scaling.' },
    { id: 'calc', year: 'Phase 08', title: 'Built Python Calculator with GUI', desc: 'Designed and developed a desktop math calculator with custom Tkinter components, safely parsing formula inputs.' },
    { id: 'ai-dev', year: 'Phase 09', title: 'Exploring AI & Development', desc: 'Studying modern neural network architectures, vector calculations, API integrations, and premium web systems.' },
    { id: 'next', year: 'Phase 10', title: 'Next Chapter...', desc: 'Actively searching for internship roles and open-source collaborative environments to build useful solutions.' }
  ];

  return (
    <div ref={appRef} className="relative min-h-screen bg-dark text-primary selection:bg-accent/20 selection:text-white font-sans">

      {/* A. Floating Navigation Pill */}
      <nav className={`fixed left-1/2 -translate-x-1/2 z-50 transition-all duration-500 w-[90%] max-w-4xl rounded-full px-6 py-4 flex items-center justify-between ${isScrolled
          ? 'top-4 glass-navbar shadow-[0_8px_32px_0_rgba(255,255,255,0.03)] border-white/5'
          : 'top-6 bg-transparent border-transparent'
        }`}>
        {/* Logo */}
        <a href="#" className="font-tight font-extrabold tracking-tight text-white flex items-center gap-2 text-base">
          <span className="w-8 h-8 rounded-full bg-white/5 border border-white/10 flex items-center justify-center text-xs font-mono text-accent font-bold">
            AK
          </span>
          AAYUSH KUMAR
        </a>

        {/* Navigation Links */}
        <div className="hidden md:flex items-center gap-8 text-[10px] font-mono tracking-widest uppercase text-secondary">
          <a href="#about" className="hover:text-accent transition-lift">About</a>
          <a href="#journey" className="hover:text-accent transition-lift">Journey</a>
          <a href="#skills" className="hover:text-accent transition-lift">Skills</a>
          <a href="#projects" className="hover:text-accent transition-lift">Projects</a>
        </div>

        {/* CTA Magnetic Button */}
        <div className="hidden md:block">
          <a href="#contact" className="btn-magnetic bg-white/5 border border-white/10 text-primary text-xs font-semibold py-2 px-5 rounded-full">
            <span className="btn-overlay bg-accent"></span>
            <span className="btn-content hover:text-dark transition-colors duration-300">
              Connect <LucideIcon name="arrowRight" className="w-4 h-4" />
            </span>
          </a>
        </div>

        {/* Mobile Toggle */}
        <button
          onClick={() => setIsMenuOpen(!isMenuOpen)}
          className="md:hidden text-primary hover:text-accent p-1 transition-colors"
          aria-label="Toggle Menu"
        >
          {isMenuOpen
            ? <svg className="w-6 h-6" fill="none" viewBox="0 0 24 24" stroke="currentColor"><path strokeLinecap="round" strokeLinejoin="round" strokeWidth={2} d="M6 18L18 6M6 6l12 12" /></svg>
            : <svg className="w-6 h-6" fill="none" viewBox="0 0 24 24" stroke="currentColor"><path strokeLinecap="round" strokeLinejoin="round" strokeWidth={2} d="M4 6h16M4 12h16M4 18h16" /></svg>
          }
        </button>

        {/* Mobile Menu Panel */}
        {isMenuOpen && (
          <div className="absolute top-16 left-0 right-0 glass-panel rounded-[2rem] p-6 mt-2 flex flex-col gap-4 border border-white/5 md:hidden animate-fade-in shadow-2xl">
            <a href="#about" onClick={() => setIsMenuOpen(false)} className="text-sm py-2 hover:text-accent border-b border-white/5 font-mono uppercase tracking-wider">About</a>
            <a href="#journey" onClick={() => setIsMenuOpen(false)} className="text-sm py-2 hover:text-accent border-b border-white/5 font-mono uppercase tracking-wider">Journey</a>
            <a href="#skills" onClick={() => setIsMenuOpen(false)} className="text-sm py-2 hover:text-accent border-b border-white/5 font-mono uppercase tracking-wider">Skills</a>
            <a href="#projects" onClick={() => setIsMenuOpen(false)} className="text-sm py-2 hover:text-accent border-b border-white/5 font-mono uppercase tracking-wider">Projects</a>
            <a href="#contact" onClick={() => setIsMenuOpen(false)} className="btn-magnetic w-full bg-accent text-dark font-bold py-3 px-6 rounded-full text-center mt-2 flex justify-center items-center gap-2 text-xs">
              Connect <LucideIcon name="arrowRight" />
            </a>
          </div>
        )}
      </nav>

      {/* B. HERO SECTION — "The Opening Shot" */}
      <section className="relative h-[100dvh] w-full overflow-hidden flex items-end justify-start pb-20 md:pb-28 px-6 md:px-20">
        {/* Soft background light aura & radial gradient grids */}
        <div className="absolute inset-0 z-0">
          <div className="absolute top-1/3 left-1/4 w-[600px] h-[600px] rounded-full bg-accent/[0.02] blur-[150px] pointer-events-none"></div>
          {/* Obsidian Gradient Layer */}
          <div className="absolute inset-0 bg-gradient-to-t from-dark via-dark/80 to-transparent"></div>
        </div>

        {/* Hero Content aligned to bottom-left third */}
        <div className="relative z-10 max-w-4xl text-left">
          <div className="hero-fade-up opacity-0 flex items-center gap-2 mb-4">
            <span className="w-2 h-2 rounded-full bg-accent/40 animate-pulse"></span>
            <span className="font-mono text-[9px] tracking-[0.25em] text-secondary font-semibold uppercase">
              STUDENT / PROBLEM SOLVER / BUILDER
            </span>
          </div>

          <h1 className="hero-fade-up opacity-0 text-5xl sm:text-7xl md:text-8xl font-tight font-black tracking-tighter leading-[0.9] text-white">
            Curiosity
            <span className="hero-fade-up opacity-0 block font-serif italic text-4xl sm:text-6xl md:text-7xl text-accent font-light mt-4 tracking-normal neon-text-glow leading-none">
              turned into code.
            </span>
          </h1>

          <p className="hero-fade-up opacity-0 mt-6 text-sm md:text-base text-secondary max-w-xl font-light leading-relaxed">
            A Computer Science student exploring AI, software development, and problem solving — documenting growth through projects, experimentation, and continuous learning.
          </p>

          <div className="hero-fade-up opacity-0 mt-8 flex flex-wrap gap-4">
            <a href="#projects" className="btn-magnetic bg-accent text-dark text-xs font-bold py-3.5 px-6 rounded-full shadow-[0_4px_25px_0_rgba(255,255,255,0.05)]">
              <span className="btn-overlay bg-white"></span>
              <span className="btn-content">
                View Projects <LucideIcon name="arrowRight" />
              </span>
            </a>
            <a href="#journey" className="btn-magnetic bg-transparent border border-white/10 text-primary text-xs font-semibold py-3.5 px-6 rounded-full hover:border-white/20">
              <span className="btn-overlay bg-white/5"></span>
              <span className="btn-content">My Journey</span>
            </a>
          </div>
        </div>

        {/* Current Focus Panel — bottom-right ambient narrative */}
        <div className="hero-fade-up opacity-0 absolute bottom-20 md:bottom-28 right-6 md:right-20 hidden md:flex flex-col gap-5 text-left pointer-events-none select-none">
          {/* Header label */}
          <div className="flex items-center gap-2.5">
            <span className="w-1.5 h-1.5 rounded-full bg-accent/50 animate-pulse flex-shrink-0"></span>
            <span className="font-mono text-[8px] tracking-[0.3em] text-accent/50 uppercase font-semibold">
              Current Focus
            </span>
          </div>

          {/* Focus items */}
          <div className="flex flex-col gap-2.5 pl-4 border-l border-white/[0.06]">
            {[
              "Artificial Intelligence",
              "Software Development",
              "Problem Solving",
              "Continuous Learning"
            ].map((item, i) => (
              <div key={i} className="flex items-center gap-2.5">
                <span className="font-mono text-[9px] text-accent/30 tracking-widest">→</span>
                <span className="font-mono text-[10px] text-secondary/70 tracking-wide font-light">{item}</span>
              </div>
            ))}
          </div>

          {/* Divider */}
          <div className="w-full h-[1px] bg-white/[0.04]"></div>

          {/* Additional context — stacked metadata */}
          <div className="flex flex-col gap-1.5 pl-4">
            {[
              "CSBS Engineering Student",
              "3 Projects Built",
              "2 Coding Competitions"
            ].map((meta, i) => (
              <span key={i} className="font-mono text-[8px] text-secondary/35 tracking-widest uppercase">
                {meta}
              </span>
            ))}
          </div>
        </div>

        {/* Scroll Indicator */}
        <div className="hero-fade-up opacity-0 absolute bottom-6 right-6 md:right-20 flex flex-col items-center gap-2 text-secondary pointer-events-none select-none">
          <span className="font-mono text-[8px] tracking-[0.2em] uppercase">SCROLL</span>
          <div className="w-[1px] h-8 bg-gradient-to-b from-secondary to-transparent"></div>
        </div>
      </section>

      {/* C. ABOUT SECTION */}
      <section id="about" className="relative py-28 md:py-36 px-6 md:px-20 max-w-6xl mx-auto z-10 border-t border-white/5">
        <div className="grid grid-cols-1 lg:grid-cols-12 gap-8 items-start">
          {/* Left Block: Heading */}
          <div className="lg:col-span-5">
            <span className="font-mono text-[9px] text-accent/60 uppercase tracking-[0.25em] font-semibold mb-4 block">
              Who I Am
            </span>
            <div className="about-text-container">
              <h2 className="text-4xl md:text-5xl font-tight font-black tracking-tight text-white leading-tight">
                {splitText("I build to learn.")}
                <span className="block text-accent font-serif italic font-light mt-1 text-3xl md:text-4xl">
                  {splitText("I learn to build.")}
                </span>
              </h2>
            </div>
          </div>

          {/* Right Block: Narrative */}
          <div className="lg:col-span-7 text-secondary font-light text-sm md:text-base leading-relaxed space-y-6 pt-4 lg:pt-8">
            <p>
              Aayush Kumar is a Computer Science student with interests in AI, software development, and problem solving. Rather than chasing titles, he focuses on building projects, understanding concepts deeply, and continuously improving.
            </p>
            <p>
              Every line of code and script represents a milestone in an ongoing journey of curiosity and growth. By taking a hands-on approach to algorithms and system paradigms, he translates abstract theoretical concepts into functional code architectures.
            </p>
          </div>
        </div>
      </section>

      {/* D. JOURNEY TIMELINE SECTION */}
      <section id="journey" className="relative py-28 md:py-36 bg-surface/30 border-y border-white/5">
        <div className="max-w-4xl mx-auto px-6 mb-16">
          <h2 className="font-mono text-[9px] text-accent/60 uppercase tracking-[0.25em] font-semibold mb-3">Milestones</h2>
          <p className="text-3xl md:text-5xl font-tight font-black tracking-tight text-white">
            Journey Timeline
          </p>
          <p className="text-secondary text-sm font-light mt-2 max-w-md">
            A documentary record of learning phases, problem solving, and software iterations.
          </p>
        </div>

        {/* Timeline Stack */}
        <div className="max-w-4xl mx-auto px-6 relative">

          {/* Vertical Center Track line */}
          <div className="absolute left-[29px] md:left-1/2 md:-translate-x-1/2 top-4 bottom-4 w-[1px] bg-white/5"></div>

          {/* Highlight indicator track that follows state */}
          <div
            className="absolute left-[29px] md:left-1/2 md:-translate-x-1/2 top-4 w-[1px] bg-accent/40 transition-all duration-700 ease-out"
            style={{
              height: `${((activeMilestone + 1) / milestones.length) * 92}%`
            }}
          ></div>

          <div className="flex flex-col gap-12 relative">
            {milestones.map((milestone, idx) => {
              const isActive = idx === activeMilestone;
              const isPast = idx < activeMilestone;
              const isEven = idx % 2 === 0;

              return (
                <div
                  key={milestone.id}
                  className={`timeline-item-trigger flex flex-col md:flex-row items-start md:items-center relative w-full transition-all duration-500 ${isActive
                      ? 'opacity-100 scale-100'
                      : 'opacity-25 scale-[0.98]'
                    }`}
                >
                  {/* Timeline Point Node */}
                  <div
                    className={`absolute left-0 md:left-1/2 -translate-x-[9px] md:-translate-x-1/2 w-[19px] h-[19px] rounded-full border flex items-center justify-center z-20 transition-all duration-500 ${isActive
                        ? 'border-accent bg-dark shadow-[0_0_10px_rgba(255,255,255,0.3)]'
                        : isPast
                          ? 'border-accent/40 bg-accent/10'
                          : 'border-white/5 bg-dark'
                      }`}
                  >
                    <div className={`w-1.5 h-1.5 rounded-full transition-colors duration-500 ${isActive ? 'bg-accent' : 'bg-transparent'}`}></div>
                  </div>

                  {/* Left Side (Empty on even on desktop, card on odd) */}
                  <div className={`w-full md:w-1/2 pl-12 md:pl-0 md:pr-12 md:text-right ${isEven ? 'md:order-1' : 'md:order-2 opacity-0 hidden md:block'}`}>
                    {isEven && (
                      <div className="inline-block">
                        <span className="font-mono text-[9px] text-accent/60 tracking-wider font-bold block mb-1">
                          {milestone.year}
                        </span>
                        <h4 className="text-base font-bold text-white tracking-tight">{milestone.title}</h4>
                        <p className="text-secondary text-xs font-light mt-1.5 max-w-sm leading-relaxed md:ml-auto">
                          {milestone.desc}
                        </p>
                      </div>
                    )}
                  </div>

                  {/* Right Side (Card on even, empty on odd) */}
                  <div className={`w-full md:w-1/2 pl-12 md:pl-12 ${isEven ? 'md:order-2 opacity-0 hidden md:block' : 'md:order-1'}`}>
                    {!isEven && (
                      <div className="inline-block text-left">
                        <span className="font-mono text-[9px] text-accent/60 tracking-wider font-bold block mb-1">
                          {milestone.year}
                        </span>
                        <h4 className="text-base font-bold text-white tracking-tight">{milestone.title}</h4>
                        <p className="text-secondary text-xs font-light mt-1.5 max-w-sm leading-relaxed">
                          {milestone.desc}
                        </p>
                      </div>
                    )}
                  </div>

                </div>
              );
            })}
          </div>

        </div>
      </section>

      {/* E. SKILLS SECTION ("Tools of the Journey") */}
      <section id="skills" className="relative py-28 md:py-36 px-6 md:px-16 max-w-6xl mx-auto z-10">
        <div className="text-center mb-16 md:mb-20">
          <h2 className="font-mono text-[9px] text-accent/60 uppercase tracking-[0.25em] font-semibold mb-3">Capabilities</h2>
          <p className="text-3xl md:text-5xl font-tight font-black tracking-tight text-white leading-tight">
            Tools of the Journey
          </p>
        </div>

        {/* Interactive Feature Cards Grid */}
        <div className="skills-grid grid grid-cols-1 lg:grid-cols-3 gap-8 items-stretch">

          {/* Card 1 — Programming Languages */}
          <div className="skill-card glass-panel p-8 rounded-custom-card border border-white/5 flex flex-col justify-between min-h-[440px] relative overflow-hidden group hover:border-white/10 transition-all duration-300">
            <div>
              <div className="flex justify-between items-center mb-6">
                <span className="p-3 bg-white/5 rounded-2xl text-accent border border-white/5">
                  <LucideIcon name="compass" />
                </span>
                <span className="font-mono text-[8px] tracking-widest text-secondary uppercase">MODULE // 01</span>
              </div>
              <h3 className="text-xl font-bold text-white mb-2 tracking-tight">Programming Languages</h3>

              {/* Primary Skill Tags */}
              <div className="flex flex-wrap gap-2 mt-4 mb-5">
                {["C", "C++", "Python"].map((skill, i) => (
                  <span key={i} className="text-[11px] font-mono text-accent bg-white/10 border border-white/10 px-4 py-2 rounded-xl font-bold tracking-wider hover:bg-accent hover:text-dark transition-all duration-300 shadow-sm">
                    {skill}
                  </span>
                ))}
              </div>

              <p className="text-xs text-secondary font-light leading-relaxed">
                Languages used to build applications, solve problems, and understand computer science fundamentals.
              </p>
            </div>

            {/* Bottom Balance Element */}
            <div className="mt-8 pt-4 border-t border-white/[0.03] flex items-center justify-between text-secondary/35 font-mono text-[8px] tracking-widest">
              <span>SYSTEM COMPILE INDEX // 01</span>
              <span className="w-1.5 h-1.5 rounded-full bg-accent/20 animate-pulse"></span>
            </div>
          </div>

          {/* Card 2 — Problem Solving */}
          <div className="skill-card glass-panel p-8 rounded-custom-card border border-white/5 flex flex-col justify-between min-h-[440px] relative overflow-hidden group hover:border-white/10 transition-all duration-300">
            <div>
              <div className="flex justify-between items-center mb-6">
                <span className="p-3 bg-white/5 rounded-2xl text-accent border border-white/5">
                  <LucideIcon name="layers" />
                </span>
                <span className="font-mono text-[8px] tracking-widest text-secondary uppercase">MODULE // 02</span>
              </div>
              <h3 className="text-xl font-bold text-white mb-2 tracking-tight">Problem Solving</h3>

              {/* Primary Skill Tags */}
              <div className="flex flex-wrap gap-2 mt-4 mb-5">
                {["Data Structures", "Algorithms", "DSA in C++"].map((skill, i) => (
                  <span key={i} className="text-[11px] font-mono text-accent bg-white/10 border border-white/10 px-4 py-2 rounded-xl font-bold tracking-wider hover:bg-accent hover:text-dark transition-all duration-300 shadow-sm">
                    {skill}
                  </span>
                ))}
              </div>

              <p className="text-xs text-secondary font-light leading-relaxed">
                Practicing logical thinking, algorithm design, and efficient problem solving.
              </p>
            </div>

            {/* Bottom Balance Element */}
            <div className="mt-8 pt-4 border-t border-white/[0.03] flex items-center justify-between text-secondary/35 font-mono text-[8px] tracking-widest">
              <span>ALGORITHM MATRIX INDEX // 02</span>
              <span className="w-1.5 h-1.5 rounded-full bg-accent/20 animate-pulse"></span>
            </div>
          </div>

          {/* Card 3 — Tools & Learning */}
          <div className="skill-card glass-panel p-8 rounded-custom-card border border-white/5 flex flex-col justify-between min-h-[440px] relative overflow-hidden group hover:border-white/10 transition-all duration-300">
            <div>
              <div className="flex justify-between items-center mb-6">
                <span className="p-3 bg-white/5 rounded-2xl text-accent border border-white/5">
                  <LucideIcon name="zap" />
                </span>
                <span className="font-mono text-[8px] tracking-widest text-secondary uppercase">MODULE // 03</span>
              </div>
              <h3 className="text-xl font-bold text-white mb-2 tracking-tight">Tools & Learning</h3>

              {/* Primary Skill Tags */}
              <div className="flex flex-wrap gap-2 mt-4 mb-5">
                {["Git", "GitHub", "VS Code", "Artificial Intelligence", "Web Development"].map((skill, i) => (
                  <span key={i} className="text-[11px] font-mono text-accent bg-white/10 border border-white/10 px-4 py-2 rounded-xl font-bold tracking-wider hover:bg-accent hover:text-dark transition-all duration-300 shadow-sm">
                    {skill}
                  </span>
                ))}
              </div>

              <p className="text-xs text-secondary font-light leading-relaxed">
                Tools and technologies currently used and explored through projects and experimentation.
              </p>
            </div>

            {/* Bottom Balance Element */}
            <div className="mt-8 pt-4 border-t border-white/[0.03] flex items-center justify-between text-secondary/35 font-mono text-[8px] tracking-widest">
              <span>DEVELOPMENT STACK INDEX // 03</span>
              <span className="w-1.5 h-1.5 rounded-full bg-accent/20 animate-pulse"></span>
            </div>
          </div>

        </div>
      </section>

      {/* F. PROJECTS SECTION */}
      <section id="projects" className="projects-section py-28 md:py-36 px-6 md:px-16 max-w-6xl mx-auto z-10 relative">
        <div className="text-center mb-20 md:mb-28">
          <h2 className="font-mono text-[9px] text-accent/60 uppercase tracking-[0.25em] font-semibold mb-3">Evidence of Learning</h2>
          <p className="text-3xl md:text-5xl font-tight font-black tracking-tight text-white">
            Projects
          </p>
          <p className="text-secondary text-sm font-light mt-2 max-w-md mx-auto">
            Practical developments built to study patterns, handle storage libraries, and master application logic.
          </p>
        </div>

        {/* Project Card Stack (Alternating Layouts) */}
        <div className="flex flex-col gap-24 max-w-5xl mx-auto">

          {/* Project 1: Python Calculator with GUI */}
          <div className="project-card-anim glass-panel rounded-custom-card border border-white/5 p-6 md:p-10 flex flex-col lg:flex-row gap-10 items-stretch justify-between w-full shadow-xl">
            <div className="w-full lg:w-1/2 flex flex-col justify-between py-2">
              <div>
                <span className="font-mono text-accent/60 text-[9px] font-bold tracking-widest block mb-4 uppercase">
                  Project 01 // Python
                </span>
                <h3 className="text-2xl md:text-3xl font-tight font-black text-white tracking-tight mb-4">
                  Python Calculator with GUI
                </h3>
                <p className="text-secondary font-light text-xs md:text-sm leading-relaxed mb-6">
                  A functional desktop utility featuring a graphical interface built using Python's Tkinter module. Safely parses math input string values, designs grid layouts, and binds application logic handlers to UI buttons.
                </p>

                {/* Highlights */}
                <div className="mb-6">
                  <span className="font-mono text-[8px] text-accent/40 tracking-wider block mb-2 uppercase">HIGHLIGHTS:</span>
                  <div className="flex flex-wrap gap-2">
                    {["User Interface Design", "Python Fundamentals", "Application Logic"].map((h, i) => (
                      <span key={i} className="text-[10px] px-3 py-1 rounded-full bg-white/5 border border-white/5 text-primary/80 font-light">{h}</span>
                    ))}
                  </div>
                </div>
              </div>

              {/* GitHub View Code Button */}
              <a
                id="github-btn-python-calc"
                href="https://github.com/Its-AayushKumar/TrackingCode/blob/main/Tkinter/Tkinter%20By%20Projects/Basic_calci%20(1).py"
                target="_blank"
                rel="noopener noreferrer"
                className="btn-magnetic inline-flex items-center gap-2 bg-white/5 border border-white/10 text-primary text-[10px] font-semibold py-2.5 px-5 rounded-full mb-5 hover:border-white/20 neon-border-glow transition-all duration-300"
              >
                <span className="btn-overlay bg-accent/10"></span>
                <span className="btn-content">
                  <LucideIcon name="github" className="w-3.5 h-3.5" />
                  View Code
                </span>
              </a>

              <div className="border-t border-white/5 pt-4">
                <span className="font-mono text-[8px] text-accent/40 tracking-wider block uppercase mb-1">LESSONS LEARNED:</span>
                <p className="text-[11px] text-secondary/80 font-light leading-relaxed">
                  Implemented custom Tkinter coordinate layouts and parsed mathematical equations safely using evaluation logic, solving edge cases like division-by-zero.
                </p>
              </div>
            </div>

            {/* Visual Panel */}
            <div className="w-full lg:w-1/2 rounded-[1.5rem] md:rounded-[2rem] overflow-hidden relative min-h-[220px] lg:min-h-auto group/img">
              <img
                src="https://images.unsplash.com/photo-1618005182384-a83a8bd57fbe?auto=format&fit=crop&w=800&q=80"
                alt="Minimalist abstract digital coordinate layout representation"
                className="w-full h-full object-cover opacity-40 transition-transform duration-700 ease-out group-hover/img:scale-105"
              />
              <div className="absolute inset-0 bg-gradient-to-t from-dark via-transparent to-transparent"></div>
            </div>
          </div>

          {/* Project 2: Library Management System */}
          <div className="project-card-anim glass-panel rounded-custom-card border border-white/5 p-6 md:p-10 flex flex-col lg:flex-row-reverse gap-10 items-stretch justify-between w-full shadow-xl">
            <div className="w-full lg:w-1/2 flex flex-col justify-between py-2">
              <div>
                <span className="font-mono text-accent/60 text-[9px] font-bold tracking-widest block mb-4 uppercase">
                  Project 02 // C++
                </span>
                <h3 className="text-2xl md:text-3xl font-tight font-black text-white tracking-tight mb-4">
                  Library Management System
                </h3>
                <p className="text-secondary font-light text-xs md:text-sm leading-relaxed mb-6">
                  A program built to manage catalogs, checkout states, and account listings. Utilizes object structures, array lists, and dynamic console listings to provide efficient utility.
                </p>

                {/* Highlights */}
                <div className="mb-6">
                  <span className="font-mono text-[8px] text-accent/40 tracking-wider block mb-2 uppercase">HIGHLIGHTS:</span>
                  <div className="flex flex-wrap gap-2">
                    {["C++ Programming", "Data Organization", "System Design Thinking"].map((h, i) => (
                      <span key={i} className="text-[10px] px-3 py-1 rounded-full bg-white/5 border border-white/5 text-primary/80 font-light">{h}</span>
                    ))}
                  </div>
                </div>
              </div>

              <div className="border-t border-white/5 pt-4">
                <span className="font-mono text-[8px] text-accent/40 tracking-wider block uppercase mb-1">LESSONS LEARNED:</span>
                <p className="text-[11px] text-secondary/80 font-light leading-relaxed">
                  Built a solid file-stream storage protocol in C++ to persist library states, handling object serialization manually without external libraries.
                </p>
              </div>
            </div>

            {/* Visual Panel */}
            <div className="w-full lg:w-1/2 rounded-[1.5rem] md:rounded-[2rem] overflow-hidden relative min-h-[220px] lg:min-h-auto group/img">
              <img
                src="https://images.unsplash.com/photo-1507842217343-583bb7270b66?auto=format&fit=crop&w=800&q=80"
                alt="Sleek modern library space in shadows"
                className="w-full h-full object-cover opacity-40 transition-transform duration-700 ease-out group-hover/img:scale-105"
              />
              <div className="absolute inset-0 bg-gradient-to-t from-dark via-transparent to-transparent"></div>
            </div>
          </div>

          {/* Project 3: Quiz Application */}
          <div className="project-card-anim glass-panel rounded-custom-card border border-white/5 p-6 md:p-10 flex flex-col lg:flex-row gap-10 items-stretch justify-between w-full shadow-xl">
            <div className="w-full lg:w-1/2 flex flex-col justify-between py-2">
              <div>
                <span className="font-mono text-accent/60 text-[9px] font-bold tracking-widest block mb-4 uppercase">
                  Project 03 // C
                </span>
                <h3 className="text-2xl md:text-3xl font-tight font-black text-white tracking-tight mb-4">
                  Quiz Application
                </h3>
                <p className="text-secondary font-light text-xs md:text-sm leading-relaxed mb-6">
                  A terminal application engineered using structured scripting. Features multiple choice questions, timer countdowns, and instant score validation indexes.
                </p>

                {/* Highlights */}
                <div className="mb-6">
                  <span className="font-mono text-[8px] text-accent/40 tracking-wider block mb-2 uppercase">HIGHLIGHTS:</span>
                  <div className="flex flex-wrap gap-2">
                    {["Core Programming Concepts", "User Interaction", "Problem Solving"].map((h, i) => (
                      <span key={i} className="text-[10px] px-3 py-1 rounded-full bg-white/5 border border-white/5 text-primary/80 font-light">{h}</span>
                    ))}
                  </div>
                </div>
              </div>

              {/* GitHub View Code Button */}
              <a
                id="github-btn-quiz-app"
                href="https://github.com/Its-AayushKumar/TrackingCode/blob/main/c_programing/Projects/Quiz/quizv4.c"
                target="_blank"
                rel="noopener noreferrer"
                className="btn-magnetic inline-flex items-center gap-2 bg-white/5 border border-white/10 text-primary text-[10px] font-semibold py-2.5 px-5 rounded-full mb-5 hover:border-white/20 neon-border-glow transition-all duration-300"
              >
                <span className="btn-overlay bg-accent/10"></span>
                <span className="btn-content">
                  <LucideIcon name="github" className="w-3.5 h-3.5" />
                  View Code
                </span>
              </a>

              <div className="border-t border-white/5 pt-4">
                <span className="font-mono text-[8px] text-accent/40 tracking-wider block uppercase mb-1">LESSONS LEARNED:</span>
                <p className="text-[11px] text-secondary/80 font-light leading-relaxed">
                  Designed structured CLI questionnaire flows with score memory arrays, practicing structural logic and low-level code organizations.
                </p>
              </div>
            </div>

            {/* Visual Panel */}
            <div className="w-full lg:w-1/2 rounded-[1.5rem] md:rounded-[2rem] overflow-hidden relative min-h-[220px] lg:min-h-auto group/img">
              <img
                src="https://images.unsplash.com/photo-1606326608606-aa0b62935f2b?auto=format&fit=crop&w=800&q=80"
                alt="Close-up of keyboard and digital metrics"
                className="w-full h-full object-cover opacity-40 transition-transform duration-700 ease-out group-hover/img:scale-105"
              />
              <div className="absolute inset-0 bg-gradient-to-t from-dark via-transparent to-transparent"></div>
            </div>
          </div>

        </div>
      </section>

      {/* G. CURRENT FOCUS SECTION */}
      <section className="py-28 md:py-36 bg-surface/30 border-y border-white/5">
        <div className="max-w-6xl mx-auto px-6 text-center mb-16">
          <h2 className="font-mono text-[9px] text-accent/60 uppercase tracking-[0.25em] font-semibold mb-3">Active Tracks</h2>
          <p className="text-3xl md:text-5xl font-tight font-black tracking-tight text-white">
            Currently Exploring
          </p>
          <p className="text-secondary text-sm font-light mt-2">
            The journey is ongoing. Here is what is active on the monitor screen right now.
          </p>
        </div>

        <div className="focus-grid grid grid-cols-1 md:grid-cols-3 gap-8 max-w-5xl mx-auto px-6">
          {/* Card 1 */}
          <div className="focus-card bg-card border border-white/5 rounded-custom-card p-8 flex flex-col justify-between hover:border-white/10 transition-all duration-300">
            <div>
              <span className="font-mono text-[8px] text-secondary block mb-2 uppercase">TRACK 01</span>
              <h3 className="text-xl font-bold text-white mb-3">Artificial Intelligence</h3>
              <p className="text-xs text-secondary font-light leading-relaxed">
                Learning the foundations of intelligent systems and understanding how modern AI tools and deep networks function.
              </p>
            </div>
            <div className="flex items-center gap-2 mt-8 font-mono text-[9px] text-accent/60">
              <span className="w-1.5 h-1.5 rounded-full bg-accent animate-pulse"></span>
              <span>NEURAL ARCS & MODELS</span>
            </div>
          </div>

          {/* Card 2 */}
          <div className="focus-card bg-card border border-white/10 rounded-custom-card p-8 flex flex-col justify-between hover:border-white/20 transition-all duration-300 relative shadow-[0_0_20px_rgba(255,255,255,0.02)]">
            <div>
              <span className="font-mono text-[8px] text-accent block mb-2 uppercase">TRACK 02</span>
              <h3 className="text-xl font-bold text-white mb-3">Software Development</h3>
              <p className="text-xs text-secondary font-light leading-relaxed">
                Building practical utility tools while solidifying object structures, dynamic algorithms, and code logic constraints.
              </p>
            </div>
            <div className="flex items-center gap-2 mt-8 font-mono text-[9px] text-accent">
              <span className="w-1.5 h-1.5 rounded-full bg-accent animate-pulse"></span>
              <span>ENGINEERING PARADIGMS</span>
            </div>
          </div>

          {/* Card 3 */}
          <div className="focus-card bg-card border border-white/5 rounded-custom-card p-8 flex flex-col justify-between hover:border-white/10 transition-all duration-300">
            <div>
              <span className="font-mono text-[8px] text-secondary block mb-2 uppercase">TRACK 03</span>
              <h3 className="text-xl font-bold text-white mb-3">Continuous Learning</h3>
              <p className="text-xs text-secondary font-light leading-relaxed">
                Consistently experimenting with new code architectures, tools, and technical concepts to increase building competence.
              </p>
            </div>
            <div className="flex items-center gap-2 mt-8 font-mono text-[9px] text-accent/60">
              <span className="w-1.5 h-1.5 rounded-full bg-accent animate-pulse"></span>
              <span>RAPID LAB ITERATIONS</span>
            </div>
          </div>
        </div>
      </section>

      {/* H. CONTACT SECTION */}
      <section id="contact" className="relative py-28 md:py-36 bg-dark border-t border-white/5 overflow-hidden">
        {/* Soft aura node */}
        <div className="absolute top-1/2 left-1/2 -translate-x-1/2 -translate-y-1/2 w-[400px] h-[400px] rounded-full bg-white/[0.01] blur-[100px] pointer-events-none z-0"></div>

        <div className="relative z-10 max-w-4xl mx-auto px-6 text-center">
          <h2 className="font-mono text-[9px] text-accent/60 uppercase tracking-[0.25em] font-semibold mb-4">Human Interface</h2>
          <p className="text-3xl sm:text-5xl md:text-6xl font-tight font-black tracking-tight text-white mb-6">
            Let's Connect
          </p>
          <p className="text-secondary font-light text-sm md:text-base max-w-xl mx-auto mb-16 leading-relaxed">
            Whether it's an opportunity, collaboration, or simply a conversation about technology, I'd love to hear from you.
          </p>

          {/* Contact Direct Link Cards */}
          <div className="grid grid-cols-1 sm:grid-cols-3 gap-4 max-w-2xl mx-auto">
            {/* Email */}
            <a
              href="mailto:aayushkumar666k@gmail.com"
              className="glass-panel border border-white/5 rounded-2xl p-4 flex flex-col items-center justify-center hover:border-accent/20 transition-all duration-300 group"
            >
              <LucideIcon name="mail" className="w-5 h-5 text-accent/60 group-hover:text-accent transition-colors mb-3" />
              <span className="font-mono text-[8px] text-secondary tracking-wider block mb-1">EMAIL</span>
              <span className="text-[10px] font-bold text-white max-w-full truncate">aayushkumar666k@gmail.com</span>
            </a>

            {/* LinkedIn */}
            <a
              href="https://www.linkedin.com/in/aayush-kumar-37982b392"
              target="_blank"
              rel="noopener noreferrer"
              className="glass-panel border border-white/5 rounded-2xl p-4 flex flex-col items-center justify-center hover:border-accent/20 transition-all duration-300 group"
            >
              <LucideIcon name="linkedin" className="w-5 h-5 text-accent/60 group-hover:text-accent transition-colors mb-3" />
              <span className="font-mono text-[8px] text-secondary tracking-wider block mb-1">LINKEDIN</span>
              <span className="text-[10px] font-bold text-white max-w-full truncate">/in/aayush-kumar-37982b392</span>
            </a>

            {/* GitHub */}
            <a
              href="https://github.com/Its-AayushKumar"
              target="_blank"
              rel="noopener noreferrer"
              className="glass-panel border border-white/5 rounded-2xl p-4 flex flex-col items-center justify-center hover:border-accent/20 transition-all duration-300 group"
            >
              <LucideIcon name="github" className="w-5 h-5 text-accent/60 group-hover:text-accent transition-colors mb-3" />
              <span className="font-mono text-[8px] text-secondary tracking-wider block mb-1">GITHUB</span>
              <span className="text-[10px] font-bold text-white max-w-full truncate">/Its-AayushKumar</span>
            </a>
          </div>
        </div>

        {/* Footer Base Info */}
        <div className="max-w-6xl mx-auto px-6 md:px-16 mt-28 md:mt-36 pt-8 border-t border-white/5 flex flex-col md:flex-row items-center justify-between gap-6 text-[10px] text-secondary">
          <div className="flex flex-col items-center md:items-start gap-1">
            <span className="font-bold text-accent font-mono tracking-widest uppercase">AAYUSH KUMAR</span>
            <span>Documenting Curiosity © 2026.</span>
          </div>

          <div className="flex items-center gap-6">
            <a href="#" className="hover:text-accent transition-colors">Privacy</a>
            <a href="#" className="hover:text-accent transition-colors">Archive Index</a>
          </div>

          {/* Operational Pulse */}
          <div className="flex items-center gap-2 font-mono tracking-widest bg-white/5 border border-white/5 px-4 py-2 rounded-full">
            <span className="w-2 h-2 rounded-full bg-success animate-pulse"></span>
            <span>SYSTEM OPERATIONAL // LEARNING & BUILDING</span>
          </div>
        </div>
      </section>

    </div>
  );
}

// ==========================================
// 3. AUXILIARY INTERACTIVE COMPONENTS
// ==========================================

// --- CARD 1: DIAGNOSTIC SHUFFLER (Languages) ---
function DiagnosticShuffler() {
  const [cards, setCards] = useState([
    { id: 'python', lang: 'Python', detail: 'Rapid building, automation scripts, Tkinter UI layouts, and exploring machine learning modeling.' },
    { id: 'cpp', lang: 'C++', detail: 'Diving deep into memory optimizations, custom class pointer lists, templates, and algorithms.' },
    { id: 'c', lang: 'C', detail: 'Low-level structural processes, custom function stacks, pointers, and memory operations.' }
  ]);

  useEffect(() => {
    const timer = setInterval(() => {
      // Loop cards by shuffling the array
      setCards(prev => {
        const next = [...prev];
        const last = next.pop();
        next.unshift(last);
        return next;
      });
    }, 3200);
    return () => clearInterval(timer);
  }, []);

  return (
    <div className="w-[260px] h-[140px] relative">
      {cards.map((card, index) => {
        let transformStyle = '';
        let opacityStyle = 0;
        let zIndex = 0;
        let borderStyle = 'border-white/5';

        if (index === 0) {
          transformStyle = 'translateY(0) scale(1)';
          opacityStyle = 1;
          zIndex = 30;
          borderStyle = 'border-accent/30 bg-card';
        } else if (index === 1) {
          transformStyle = 'translateY(16px) scale(0.94)';
          opacityStyle = 0.6;
          zIndex = 20;
        } else if (index === 2) {
          transformStyle = 'translateY(32px) scale(0.88)';
          opacityStyle = 0.3;
          zIndex = 10;
        }

        return (
          <div
            key={card.id}
            className={`absolute top-0 left-0 w-full h-[105px] rounded-2xl p-4 bg-surface border ${borderStyle} flex flex-col justify-center transition-all duration-500 ease-[cubic-bezier(0.34,1.56,0.64,1)]`}
            style={{
              transform: transformStyle,
              opacity: opacityStyle,
              zIndex: zIndex
            }}
          >
            <div className="flex items-center gap-2 mb-1.5">
              <span className="w-1.5 h-1.5 rounded-full bg-accent animate-pulse"></span>
              <span className="font-mono font-bold text-xs text-white">{card.lang}</span>
            </div>
            <p className="text-[10px] text-secondary leading-relaxed font-light">{card.detail}</p>
          </div>
        );
      })}
    </div>
  );
}

// --- CARD 2: TELEMETRY TYPEWRITER (DSA / Problem Solving) ---
function TelemetryTypewriter() {
  const lines = [
    "COMPILING: AVL-TREE // STABLE",
    "SEARCH: DIJKSTRA PATH CALCULATED",
    "TIME COMPLEXITY: O(N LOG N)",
    "SPACE COMPLEXITY: O(N) ALLOCATED",
    "LEETCODE: EXECUTING BENCHMARKS",
    "STATUS: ALL TESTS PASSED SUCCESSFULLY"
  ];

  const [activeLineIndex, setActiveLineIndex] = useState(0);
  const [typedText, setTypedText] = useState('');
  const [isDeleting, setIsDeleting] = useState(false);

  useEffect(() => {
    let timer;
    const currentFullText = lines[activeLineIndex];

    if (!isDeleting) {
      if (typedText.length < currentFullText.length) {
        timer = setTimeout(() => {
          setTypedText(currentFullText.slice(0, typedText.length + 1));
        }, 55);
      } else {
        timer = setTimeout(() => {
          setIsDeleting(true);
        }, 2200);
      }
    } else {
      if (typedText.length > 0) {
        timer = setTimeout(() => {
          setTypedText(currentFullText.slice(0, typedText.length - 1));
        }, 25);
      } else {
        setIsDeleting(false);
        setActiveLineIndex((prev) => (prev + 1) % lines.length);
      }
    }

    return () => clearTimeout(timer);
  }, [typedText, isDeleting, activeLineIndex]);

  return (
    <>
      <div className="flex items-center justify-between border-b border-white/5 pb-2">
        <span className="text-[9px] font-semibold text-accent/80 tracking-wider font-mono">PROBLEM SOLVING CONSOLE</span>
        <div className="flex items-center gap-1.5">
          <span className="w-1.5 h-1.5 rounded-full bg-success animate-pulse"></span>
          <span className="text-[8px] text-secondary tracking-widest font-bold font-mono">LIVE EVAL</span>
        </div>
      </div>

      <div className="flex-1 flex flex-col justify-center font-mono text-[10px] leading-relaxed text-primary/80 px-1 py-3">
        <div>&gt; {typedText}<span className="inline-block w-1.5 h-3 bg-accent ml-1 cursor-blink"></span></div>
        <div className="text-[8px] text-secondary/40 mt-3">&gt; DRIFT TOLERANCE: 0.00ms</div>
        <div className="text-[8px] text-secondary/40">&gt; ALGORITHMS VERIFIED</div>
      </div>

      <div className="text-[8px] text-secondary/30 border-t border-white/5 pt-2 flex justify-between font-mono">
        <span>DSA LEDGER</span>
        <span>LAT: 19.0760° N</span>
      </div>
    </>
  );
}

// --- CARD 3: CURSOR PROTOCOL SCHEDULER (Daily Workflow) ---
function CursorScheduler() {
  const containerRef = useRef(null);
  const cursorRef = useRef(null);

  const [activeDays, setActiveDays] = useState({ M: false, W: false, F: false });
  const [powerReserve, setPowerReserve] = useState(15);
  const [isSaved, setIsSaved] = useState(false);

  useEffect(() => {
    const ctx = gsap.context(() => {
      const tl = gsap.timeline({ repeat: -1, repeatDelay: 1 });

      // Clean resetting state
      tl.call(() => {
        setActiveDays({ M: false, W: false, F: false });
        setPowerReserve(15);
        setIsSaved(false);
      });

      // Show cursor, move to M (Mon)
      tl.to(cursorRef.current, { opacity: 1, x: 20, y: 35, duration: 1, ease: 'power2.out' });
      // Click animation on M
      tl.to(cursorRef.current, { scale: 0.8, duration: 0.1, yoyo: true, repeat: 1 });
      tl.call(() => {
        setActiveDays(prev => ({ ...prev, M: true }));
        setPowerReserve(45);
      });

      // Move to W (Wed)
      tl.to(cursorRef.current, { x: 90, y: 35, duration: 0.8, ease: 'power2.inOut' });
      // Click animation on W
      tl.to(cursorRef.current, { scale: 0.8, duration: 0.1, yoyo: true, repeat: 1 });
      tl.call(() => {
        setActiveDays(prev => ({ ...prev, W: true }));
        setPowerReserve(75);
      });

      // Move to F (Fri)
      tl.to(cursorRef.current, { x: 160, y: 35, duration: 0.8, ease: 'power2.inOut' });
      // Click animation on F
      tl.to(cursorRef.current, { scale: 0.8, duration: 0.1, yoyo: true, repeat: 1 });
      tl.call(() => {
        setActiveDays(prev => ({ ...prev, F: true }));
        setPowerReserve(100);
      });

      // Move to Deploy Sync Button
      tl.to(cursorRef.current, { x: 180, y: 85, duration: 1, ease: 'power2.inOut' });
      // Click Sync Button
      tl.to(cursorRef.current, { scale: 0.8, duration: 0.1, yoyo: true, repeat: 1 });
      tl.call(() => {
        setIsSaved(true);
      });

      // Fade out cursor
      tl.to(cursorRef.current, { opacity: 0, duration: 0.5, delay: 1.5 });

    }, containerRef);

    return () => ctx.revert();
  }, []);

  return (
    <div ref={containerRef} className="relative w-full h-full font-mono text-[9px] select-none text-secondary">
      {/* Power Reserve Meter */}
      <div className="flex justify-between items-center mb-3">
        <span className="text-accent/60">WEEKLY DEV SESSIONS</span>
        <span className="font-bold text-white">{powerReserve}%</span>
      </div>

      {/* Charge Progress bar */}
      <div className="w-full h-1.5 bg-white/5 border border-white/5 rounded-full overflow-hidden mb-4">
        <div
          className="h-full bg-accent rounded-full transition-all duration-500 ease-out shadow-[0_0_8px_rgba(255,255,255,0.2)]"
          style={{ width: `${powerReserve}%` }}
        ></div>
      </div>

      {/* S M T W T F S Calendar grid */}
      <div className="flex justify-between items-center gap-1.5 relative px-2 py-1 mb-4">
        {['S', 'M', 'T', 'W', 'T', 'F', 'S'].map((day, idx) => {
          const isActive = day === 'M' ? activeDays.M : day === 'W' ? activeDays.W : day === 'F' ? activeDays.F : false;
          return (
            <div
              key={idx}
              className={`w-7 h-7 rounded-lg border flex items-center justify-center font-bold text-[9px] transition-all duration-300 ${isActive
                  ? 'border-accent bg-accent/10 text-white shadow-[0_0_8px_rgba(255,255,255,0.08)]'
                  : 'border-white/5 bg-white/5 text-secondary/35'
                }`}
            >
              {day}
            </div>
          );
        })}
      </div>

      {/* Build deployment validation trigger */}
      <div className="flex justify-between items-center">
        <span className="text-[8px] text-secondary/40">GIT SYNC</span>
        <button
          className={`px-3 py-1.5 rounded-full border text-[9px] font-bold flex items-center gap-1.5 transition-all duration-300 ${isSaved
              ? 'bg-success/10 border-success/30 text-success shadow-[0_0_10px_rgba(34,197,94,0.15)]'
              : 'bg-white/5 border-white/5 text-white'
            }`}
        >
          {isSaved ? 'COMMITTED' : 'SYNC SPRINT'}
          <svg className={`w-2.5 h-2.5 ${isSaved ? 'text-success' : 'text-white'}`} fill="none" viewBox="0 0 24 24" stroke="currentColor">
            <polyline points="20 6 9 17 4 12" />
          </svg>
        </button>
      </div>

      {/* Visual Cursor Element */}
      <div
        ref={cursorRef}
        className="absolute top-0 left-0 pointer-events-none z-40 opacity-0 transform origin-top-left"
        style={{ width: '12px', height: '18px' }}
      >
        <svg viewBox="0 0 12 18" fill="none" xmlns="http://www.w3.org/2000/svg" className="drop-shadow-[0_2px_4px_rgba(255,255,255,0.2)]">
          <path d="M0 0V16L4.5 12L7.5 17.5L10 16L7 10.5L12 10.5L0 0Z" fill="#E5E7EB" stroke="black" strokeWidth="1" />
        </svg>
      </div>
    </div>
  );
}

// ==========================================
// 4. SPLIT TEXT HELPER
// ==========================================

function splitText(text) {
  return text.split(' ').map((word, idx) => (
    <span key={idx} className="about-word inline-block mr-[0.3em] origin-bottom-left">
      {word}
    </span>
  ));
}

// ==========================================
// 5. REACT ENTRYPOINT MOUNTING
// ==========================================

const container = document.getElementById('root');
const root = createRoot(container);
root.render(<App />);
